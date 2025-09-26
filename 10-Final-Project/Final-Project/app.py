from flask import Flask, render_template, request, jsonify
import requests
import os

app = Flask(__name__)


API_KEY = os.environ.get("OPENWEATHER_API_KEY",
                         "15133bb2990d7b7cdf9aea19ab4a5d78")
WEATHER_URL = "https://api.openweathermap.org/data/2.5/weather"


@app.route("/")
def home():
    return render_template("index.html")


@app.route("/weather")
def get_weather():
    city = request.args.get("city")
    if not city:
        return jsonify({"error": "City not provided"}), 400

    params = {
        "q": city,
        "appid": API_KEY,
        "units": "metric",
        "lang": "pt_br"
    }

    try:
        response = requests.get(WEATHER_URL, params=params, timeout=10)

        try:
            data = response.json()
        except ValueError:
            return jsonify({"error": "Invalid Weather API Response", "raw": response.text}), 502


        if response.status_code != 200:
            message = data.get("message") if isinstance(data, dict) else None
            return jsonify({"error": "City not found", "detail": message}), 404


        result = {
            "name": data.get("name"),
            "temp": data.get("main", {}).get("temp"),
            "description": data.get("weather", [{}])[0].get("description"),
            "icon": data.get("weather", [{}])[0].get("icon"),
            "main": data.get("weather", [{}])[0].get("main"),
            "country": data.get("sys", {}).get("country"),
            "humidity": data.get("main", {}).get("humidity"),
            "wind": data.get("wind", {}).get("speed"),
            "timezone": data.get("timezone"),
            "dt": data.get("dt")
        }
        return jsonify(result)

    except requests.RequestException as e:
        return jsonify({"error": "Error connecting to the Weather API", "detail": str(e)}), 500


if __name__ == "__main__":
    app.run(debug=True)
