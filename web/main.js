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
    
    function partirDroite(event){
        event.preventDefault();
        const img = document.getElementById('vieux');
        img.style.transform = 'translate(150vw, -50%)';

        setTimeout(() => {
        window.location = event.target.href;
      }, 2000);
    }


    partirDroite();

    window.onload = function() {
      const img = document.getElementById('vieuxPere');

      img.style.transform = 'translate(-150vw, -50%)'; 


      setTimeout(() => {
    img.style.transform = 'translate(-50%, -5%)';
  }, 50);
};

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
    function findShortestPath(graph, start, goal) {
        const queue = [[start]];
        const visited = new Set();

        while (queue.length > 0) {
            const path = queue.shift();
            const node = path[path.length - 1];

            if (node === goal) return path;

            if (!visited.has(node)) {
            visited.add(node);
            for (const neighbor of graph[node] || []) {
                const newPath = [...path, neighbor];
                queue.push(newPath);
                }
            }
        }
        return null;
    }
    function marquerChoix(chapitreActuel, cheminOptimal) {
        const nextNode = cheminOptimal[cheminOptimal.indexOf(chapitreActuel) + 1];

        const choix = document.querySelectorAll("choice");
        choix.forEach((choice) => {
        const idref = choice.getAttribute("idref");
  
        const existingIcon = choice.querySelector("i.fa-path-icon");
        if (existingIcon) existingIcon.remove();

        const icon = document.createElement("i");
        icon.classList.add("fa-path-icon", "fas"); 

        if (idref === nextNode) {
            icon.classList.add("fa-check-circle"); 
            icon.style.color = "limegreen";
        }   
        else if (idref === "09") {
            icon.classList.add("fa-skull-crossbones");
            icon.style.color = "crimson";
        }   
        else {
            icon.classList.add("fa-question-circle"); 
            icon.style.color = "gray";
        }
        icon.style.marginLeft = "8px";
        choice.appendChild(icon);
        });
    
    }
    const chapitreActuel = idref; 
    const cheminVersVictoire = findShortestPath(graph, chapitreActuel, "10");

    if (cheminVersVictoire) {
        marquerChoix(chapitreActuel, cheminVersVictoire);
    }
}




main();