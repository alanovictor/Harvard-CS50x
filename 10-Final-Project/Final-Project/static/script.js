async function getUserCity() {
  try {
    const res = await fetch("http://ip-api.com/json/");
    const data = await res.json();
    if (data && data.status === "success") {
      return data.city;
    }
    return null;
  } catch (e) {
    console.error("Error fetching location:", e);
    return null;
  }
}

// convert hour local
function getLocalTime(timezone) {
  // pega horário UTC atual em milissegundos
  const nowUtc = Date.now();

  // aplica o offset da cidade (segundos -> ms)
  const localDate = new Date(nowUtc + timezone * 1000);

  return {
    hours: localDate.getUTCHours(),
    formatted: localDate.toLocaleTimeString("pt-BR", {
      timeZone: "UTC", // força a usar UTC sem aplicar fuso local de novo
      hour: "2-digit",
      minute: "2-digit"
    })
  };
}


// elements
const cityInput = document.querySelector("#city-input");
const searchBtn = document.querySelector("#search");

const cityElement = document.querySelector("#city");
const tempElement = document.querySelector("#temperature span");
const descElement = document.querySelector("#description");
const weatherIconElement = document.querySelector("#weather-icon");
const countryElement = document.querySelector("#country");
const humidityElement = document.querySelector("#humidity span");
const windElement = document.querySelector("#wind span");
const msgElement = document.querySelector("#msg");

// flask api
async function getWeatherData(city) {
  try {
    const res = await fetch(`/weather?city=${encodeURIComponent(city)}`);
    const data = await res.json();
    return data;
  } catch (e) {
    console.error("Error in /weather request:", e);
    return { error: "Error getting weather data" };
  }
}

// show data on screen
async function showWeatherData(city) {
  if (!city) return;
  const data = await getWeatherData(city);

  if (data.error) {
    alert(data.error);
    return;
  }

  // fill out (protegendo contra undefined)
  cityElement.innerText = data.name || city;
  tempElement.innerText = Number.isFinite(data.temp) ? parseInt(data.temp) : "--";
  descElement.innerText = data.description || "--";
  if (data.icon) {
    weatherIconElement.setAttribute("src", `http://openweathermap.org/img/wn/${data.icon}.png`);
  } else {
    weatherIconElement.removeAttribute("src");
  }
  if (data.country) {
    countryElement.setAttribute("src", `https://flagsapi.com/${data.country}/shiny/64.png`);
  } else {
    countryElement.removeAttribute("src");
  }
  humidityElement.innerText = data.humidity != null ? `${data.humidity}%` : "--";
  windElement.innerText = data.wind != null ? `${data.wind} km/h` : "--";

  // hour local city ( dt + timezone)
  const localTime = getLocalTime(data.timezone || 0);
  msgElement.innerHTML = `It is now ${localTime.formatted} in ${data.name || city}${data.country ? ", " + data.country : ""}`;

  // start/att clock
  startClock(data.dt || Math.floor(Date.now() / 1000), data.timezone || 0);

  // Fundo de acordo com clima + hora local da cidade
  aplicarFundoClima((data.description || "").toLowerCase(), localTime.hours);
}

// event search
if (searchBtn) {
  searchBtn.addEventListener("click", (e) => {
    e.preventDefault();
    const city = cityInput.value.trim();
    if (city) showWeatherData(city);
  });
}

// 6 possibles back
function aplicarFundoClima(description, hour) {
  const body = document.body;
  let img = "";

  const isDay = hour >= 6 && hour < 18; // 6h às 18h => dia

  if (description.includes("chuva")) {
    img = isDay ? "/static/bg_rainy_day.jpg" : "/static/bg_rainy_night.jpg";
  } else if (description.includes("nuvens") || description.includes("nublado")) {
    img = isDay ? "/static/bg_cloudy_day.jpg" : "/static/bg_cloudy_night.jpg";
  } else {
    img = isDay ? "/static/bg_clear_day.jpg" : "/static/bg_clear_night.jpg";
  }

  body.style.backgroundImage = `url('${img}')`;
  body.style.backgroundSize = "cover";
  body.style.backgroundPosition = "center";
  body.style.backgroundRepeat = "no-repeat";
  body.style.transition = "background 0.6s ease-in-out";
}

// clock
let clockInterval = null;

function startClock(initialDt, timezone) {
  if (clockInterval) {
    clearInterval(clockInterval);
    clockInterval = null;
  }

  let currentDt = Number(initialDt) || Math.floor(Date.now() / 1000);

  const hourEl = document.getElementById("hour");
  const minuteEl = document.getElementById("minute");
  const secondEl = document.getElementById("second");


  if (!hourEl || !minuteEl || !secondEl) return;


  updateClockNow();

  clockInterval = setInterval(() => {
    currentDt += 1; // incrementa 1 segundo
    updateClockNow();
  }, 1000);

  function updateClockNow() {
    const localMs = (currentDt + (Number(timezone) || 0)) * 1000;
    const localDate = new Date(localMs);

    const hours = localDate.getUTCHours();
    const minutes = localDate.getUTCMinutes();
    const seconds = localDate.getUTCSeconds();

    const hourDeg = (hours % 12) * 30 + minutes * 0.5;
    const minuteDeg = minutes * 6 + seconds * 0.1;
    const secondDeg = seconds * 6;

    hourEl.style.transform = `rotate(${hourDeg}deg)`;
    minuteEl.style.transform = `rotate(${minuteDeg}deg)`;
    secondEl.style.transform = `rotate(${secondDeg}deg)`;
  }
}

// inicialization
window.addEventListener("load", async () => {

  const now = new Date();
  msgElement.innerHTML = `Agora são ${now.toLocaleTimeString("pt-BR", { hour: "2-digit", minute: "2-digit" })} (PC)`;

  const userCity = await getUserCity();
  if (userCity) {
    showWeatherData(userCity);
  } else {
    msgElement.innerHTML = "We were unable to automatically detect your city.";
  }
});
