const button = document.getElementById("playButton");
const audio = document.getElementById("myAudio");

button.addEventListener("click", function() {
    if(audio.paused) {
        audio.play();
        button.textContent = "Stop Music";
    } else {
        audio.pause();
        button.textContent = "Play Music";
    }
});

