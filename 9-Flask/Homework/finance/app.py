import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    user_id = session["user_id"]

    # Pega todas as transações do usuário agrupadas por símbolo
    transactions = db.execute(
        "SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = ? GROUP BY symbol",
        user_id
    )

    holdings = []
    total_value = 0

    for row in transactions:
        symbol = row["symbol"]
        shares = row["total_shares"]

        # Ignorar ações vendidas totalmente (zero)
        if shares > 0:
            quote = lookup(symbol)
            price = quote["price"]
            total = shares * price
            total_value += total

            holdings.append({
                "symbol": symbol,
                "shares": shares,
                "price": usd(price),
                "total": usd(total)
            })

    # Pega o cash do usuário
    rows = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    cash = rows[0]["cash"]

    grand_total = total_value + cash

    return render_template("index.html", holdings=holdings, cash=usd(cash), grand_total=usd(grand_total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "GET":
        # Exibe o formulário para o usuário inserir símbolo e quantidade
        return render_template("buy.html")

    else:
        # POST: o usuário enviou o formulário
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")

        # Validar símbolo e quantidade
        if not symbol:
            return apology("must provide symbol", 400)
        if not shares or not shares.isdigit() or int(shares) < 1:
            return apology("must provide a positive number of shares", 400)

        shares = int(shares)

        # Consultar o preço da ação
        quote = lookup(symbol)
        if quote is None:
            return apology("invalid symbol", 400)

        price = quote["price"]
        total_cost = shares * price

        # Buscar o cash atual do usuário
        user_id = session["user_id"]
        rows = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        cash = rows[0]["cash"]

        # Verificar se o usuário tem saldo suficiente
        if cash < total_cost:
            return apology("not enough cash", 400)

        # 1) Atualizar o saldo do usuário
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", total_cost, user_id)

        # 2) Registrar a transação na tabela transactions
        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)",
            user_id, symbol, shares, price
        )

        # Redirecionar para a página inicial (index) para ver o novo portfólio
        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # Pegar o id do usuário logado
    user_id = session["user_id"]

    # Consultar todas as transações do usuário
    transactions = db.execute(
        "SELECT symbol, shares, price, transacted AS time FROM transactions WHERE user_id = ? ORDER BY transacted DESC",
        user_id
    )

    # Renderizar template enviando as transações
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "GET":
        # Exibir formulário vazio
        return render_template("quote.html", quote=None)
    else:
        # POST: usuário enviou o símbolo
        symbol = request.form.get("symbol").upper()

        if not symbol:
            return apology("must provide symbol", 400)

        quote_data = lookup(symbol)
        if quote_data is None:
            return apology("invalid symbol", 400)

        # Renderizar o template, passando o quote
        return render_template("quote.html", quote=quote_data)


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "GET":
        return render_template("register.html")
    else:  # POST
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if not username:
            return apology("must provide username", 400)
        if not password:
            return apology("must provide password", 400)
        if not confirmation:
            return apology("must confirm password", 400)
        if password != confirmation:
            return apology("passwords do not match", 400)

        # Verificar se o username já existe
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)
        if len(rows) > 0:
            return apology("username already taken", 400)

        # Gerar hash da senha
        hash_pw = generate_password_hash(password)

        # Inserir novo usuário no banco
        new_user_id = db.execute(
            "INSERT INTO users (username, hash) VALUES (?, ?)",
            username, hash_pw
        )

        # Guardar o id do usuário na sessão
        session["user_id"] = new_user_id

        # Redirecionar para a página inicial
        return redirect("/login")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    user_id = session["user_id"]

    if request.method == "GET":
        # Pegar todas as ações que o usuário possui
        rows = db.execute("""
            SELECT symbol, SUM(shares) AS total
            FROM transactions
            WHERE user_id = ?
            GROUP BY symbol
            HAVING total > 0
        """, user_id)

        symbols = [row["symbol"] for row in rows]
        return render_template("sell.html", symbols=symbols)

    else:
        # POST: usuário enviou o formulário
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")

        # Validar input
        if not symbol:
            return apology("must provide symbol", 400)
        if not shares or not shares.isdigit() or int(shares) < 1:
            return apology("must provide a positive number of shares", 400)

        shares = int(shares)

        # Consultar quantas ações o usuário possui desse símbolo
        rows = db.execute("""
            SELECT SUM(shares) AS total
            FROM transactions
            WHERE user_id = ? AND symbol = ?
            GROUP BY symbol
        """, user_id, symbol)

        if not rows or rows[0]["total"] < shares:
            return apology("not enough shares", 400)

        # Consultar o preço atual da ação
        quote = lookup(symbol)
        if quote is None:
            return apology("invalid symbol", 400)

        price = quote["price"]
        total_sale = shares * price

        # 1) Registrar a venda na tabela transactions (shares negativas)
        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)",
            user_id, symbol, -shares, price
        )

        # 2) Atualizar o cash do usuário
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", total_sale, user_id)

        # Redirecionar para o index
        return redirect("/")
