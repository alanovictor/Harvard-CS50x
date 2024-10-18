import csv

from collections import Counter

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = Counter()

    for row in reader:
        favorite = row["problem"]
        counts[favorite] += 1

favorite = input("Favorite: ")
print(f"{favorite}: {counts[favorite]}")


# Esse código faz a contagem de quantas vezes cada valor aparece na coluna "problem" de um arquivo CSV chamado #favorites.csv. Vamos detalhar cada parte:Importações:pythonCopiar código
#
# import csv
# from collections import Counter
# O módulo csv é importado para ler o arquivo CSV.
# O Counter da biblioteca collections é utilizado para contar quantas vezes cada item aparece.
# Abrindo o arquivo CSV:
#
# python
# Copiar código
# with open("favorites.csv", "r") as file:
reader = csv.DictReader(file)
# O arquivo favorites.csv é aberto no modo de leitura ("r").
# O csv.DictReader(file) lê o arquivo CSV e trata cada linha como um dicionário, onde as chaves são os nomes das #colunas.
# Inicializando o contador:
#
# python
# Copiar código
# counts = Counter()
# Um objeto Counter é criado para armazenar e contar os valores da coluna "problem".
# Iterando pelas linhas do arquivo:
#
# python
# Copiar código
# for row in reader:
favorite = row["problem"]
counts[favorite] += 1
# O código percorre cada linha (row) do arquivo CSV.
# A variável favorite captura o valor da coluna "problem" de cada linha.
# O contador counts[favorite] é incrementado para contar quantas vezes cada valor de "problem" aparece.
# Entrada do usuário e exibição do resultado:
#
# python
# Copiar código
# favorite = input("Favorite: ")
# print(f"{favorite}: {counts[favorite]}")
# O programa solicita que o usuário insira um valor (o favorito).
Em seguida, o código imprime quantas vezes esse valor específico apareceu na coluna "problem".
# Exemplo de Funcionamento:
# Suponha que o arquivo favorites.csv tenha o seguinte conteúdo:
#
# lua
# Copiar código
# problem
# math
# science
# math
# english
# science
# math
# Se o usuário inserir math como favorito, o programa retornará:
#
# lua
# Copiar código
# math: 3
