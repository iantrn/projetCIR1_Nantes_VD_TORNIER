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
    const url = window.location.href;

      if (url.includes("7.html")){
        const jeu = document.createElement("div");
        jeu.className = "Jeu";
        jeu.innerHTML =  `
          <div class="game">
            <button class="start-btn">Start</button>
            <div class="game-info">
              <span class="time">Temps : 0</span>
              <span class="score">Score : 0</span>
            </div>
            <div class="mini-jeu">
            </div>
            <button class="quit-btn">Quit</button>
          </div>
        `;
        document.body.appendChild(jeu);
      }

      let mini_jeu = document.querySelector('.mini-jeu');
      let start_btn = document.querySelector('.start-btn');
      let quit_btn = document.querySelector('.quit-btn');
      let time = document.querySelector('.time');
      let score = document.querySelector('.score');

      quit_btn.onclick = function(){
        window.location.href = "9.html"
      }
      
      start_btn.onclick = function(){
        let score = 0;
        let time = 15;
        mini_jeu.innerHTML = "";

        let interval = setInterval(function showTarget(){

          let target = document.createElement('img');
          target.id="target";
          target.src="../web/images/silly.png"
          mini_jeu.appendChild(target);
          target.style.top = Math.random() * (500 - target.offsetHeight) + 'px';
          target.style.left = Math.random() * (600 - target.offsetWidth) + 'px';


          setTimeout(function(){
            target.remove();
          }, 2000)

          target.onclick = function(){
            score += 1;
            target.style.display = 'none';

          }
          time-= 1;

          score.innerHTML = `Score : ${score}`
          time.innerHTML = ` Temps : ${time}`

          if(time == 0){
            window.location.href = "9.html"
          }

          if(score == 10){
            window.location.href = "10.html"
          }

        }, 1000);
      }




}




main();