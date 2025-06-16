function main() {
    const links = document.querySelectorAll('.choice');
    const overlay = document.getElementById('overlay');

    links.forEach(link => {
        link.addEventListener('click', function(event) {
        event.preventDefault();
        overlay.classList.add('active');
        setTimeout(() => {
            overlay.classList.remove('active');
            setTimeout(() => {
            window.location.href = link.href;
                }, 2000);
            }, 2000);
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

    const graph = { 
        "01": ["02", "03"],
        "02": ["03", "04", "05"],
        "03": ["06", "09"],         
        "04": ["09"],
        "05": ["02"],
        "06": ["07", "08"],
        "07": ["09"],
        "08": ["10"],
        "09": [],
        "10": [],
    }
    function shortestPath(current, goal) {
        
    }


}




main();