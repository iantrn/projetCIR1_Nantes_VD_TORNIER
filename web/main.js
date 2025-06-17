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


    window.onload = function() {
      const vieux = document.getElementById('vieux');
  
      // Crée l'animation d'entrée
      vieux.style.animation = 'entreeGauche 3s ease-in-out forwards';

      const styleSheet = document.createElement("style");
      styleSheet.innerHTML = `
        @keyframes entreeGauche {
          0% { transform: translate(-150vw, -5%); }
          100% { transform: translate(-50%, -5%); }
        }
        @keyframes sortieDroite {
          0% { transform: translate(-50%, -5%); }
          100% { transform: translate(150vw, -5%); }
      }
      `;
      document.head.appendChild(styleSheet);

      // Ajoute l'écoute sur tous les liens
      document.querySelectorAll('a').forEach(link => {
        link.addEventListener('click', function(event) {
          event.preventDefault();
      
          // Déclenche l'animation de sortie
          vieux.style.animation = 'sortieDroite 3s ease-in-out forwards';

          setTimeout(() => {
            window.location = link.href;
          }, 3000);
        });
      });
    };
}




main();