# TIME & HOUR
#### Video Demo:  [https://www.youtube.com/watch?v=7Bbe1A7JyHM]
#### Description:
How does the application work?
The user opens the website, Flask sends index.html, and then JavaScript runs in the browser and discovers the user's city by IP address.
The user enters the name of any city in the world, including the country. The JavaScript requests ``/weather?city=CITY`` from Flask, and Flask then queries the OpenWeather API and returns the data in JSON.
The JavaScript reads the JSON and updates the website's background based on the time and weather of the scanned location, changing the background image and updating the icons, clock and description via CSS.

 Time & Hour – CS50 Final Project
 Description

Time & Hour is a web application built as my final project for CS50x – Introduction to Computer Science.

The app combines weather information and local time into a single interface. A user can look up any city in the world and see:

 Current temperature

 Weather description (clear sky, cloudy, rainy, etc.)

 Humidity and 💨 wind speed

 The country flag

 The local time of the chosen city

 A live analog clock showing the city’s time

Dynamic background images that change depending on the weather and time (day/night, clear, cloudy, rainy)

 Goal

The main idea was to practice integrating a Python back end (Flask) with a JavaScript front end, while also working with real-time data from external APIs.

The app is simple, but it shows how weather and time can be presented together in an interactive way.

 Technologies

Python 3 – back end

Flask – web framework for routes and API requests

Requests (Python) – to fetch data from OpenWeather on the server side

HTML5 / CSS3 / JavaScript (ES6) – front end

OpenWeather API – weather and local time data

ip-api – to automatically detect the user’s city by IP

FontAwesome – icons

FlagsAPI – country flags

 This project doesn’t use a database — everything is fetched live from APIs.

 How to Install and Run (Flask version)

Clone the repository

git clone https://github.com/your-username/time-and-hour.git
cd time-and-hour


Create and activate a virtual environment

python3 -m venv venv
source venv/bin/activate      # Linux/Mac
venv\Scripts\activate         # Windows


Install the requirements

pip install -r requirements.txt


Run the Flask app

flask run


Open http://127.0.0.1:5000/ in your browser.

Project Structure
time-and-hour/
├── app.py              # Flask server
├── requirements.txt    # dependencies
├── /templates
│   └── index.html      # main page
├── /static
│   ├── style.css       # styles
│   ├── script.js       # front-end logic
│   └── images...       # background images

Usage

When you open the app, it automatically detects your city using your IP.

The screen shows:

Current weather

Analog clock set to your local time

Background that changes with weather and time

You can also search for any city in the input box.

The page updates with:

City name and country flag

Temperature and weather description

Humidity and wind speed

Local time in text and on the analog clock

A new background depending on day/night and the weather

Design Choices

Flask was chosen so the API key could stay hidden and to practice Python back end development.

JavaScript was used for a dynamic interface without reloading the page.

The analog clock makes the time display more visual and interactive.

Background images improve the user experience by matching the current conditions.

No database was used since the focus was on live API integration.

Future Improvements

Show a 5-day forecast instead of only current weather.

Add option to switch between Celsius and Fahrenheit.

Better responsive design for mobile devices.

Use GPS geolocation in addition to IP detection.

Save a history of searched cities.

Add light/dark theme toggle.
