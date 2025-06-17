function main() {    
    window.addEventListener("DOMContentLoaded", () => {
    const overlay = document.getElementById("overlay");
    setTimeout(() => {
        overlay.classList.add("fade-out");
        }, 100);
    });


    const links = document.querySelectorAll("a.choice");
    const image_vieux = document.getElementById("vieux");
    links.forEach(link => {
        link.addEventListener('click', function(event) {
        event.preventDefault();
        const overlay = document.getElementById("overlay");
        overlay.classList.remove("fade-out");
        overlay.classList.add("active");   
        overlay.style.opacity = 1;

        setTimeout(() => {
            window.location.href = link.href;
            }, 1000);
        });
    });

    function backgroundMusic() {
    const audio = document.getElementById('background-audio');
    const sound_button = document.getElementById('sound_button');
    const icon = sound_button.querySelector('i');
    audio.play();

    sound_button.onclick = function () {
      audio.muted = !audio.muted;

      if (audio.muted) {
        icon.className = "fas fa-volume-mute";
      } else {
        icon.className = "fas fa-volume-up";
      }
    };
  }
    window.addEventListener('DOMContentLoaded', backgroundMusic);
    function returnHome(event) {
        event.preventDefault();
        if (confirm("Voulez-vous recommencer votre aventure ? ") == true) {  
            window.location.href = "../export/1.html";   
        }
    }
    let home_button = document.getElementById("home_button");   
    home_button.addEventListener("click", returnHome);

}




main();