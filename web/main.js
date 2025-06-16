function main() {
const links = document.querySelectorAll('.choice');
  const overlay = document.getElementById('overlay');

  links.forEach(link => {
        link.addEventListener('click', function(event) {
      event.preventDefault(); // bloque la navigation immédiate

      // Affiche le fond noir en opacity 1 (fade-in)
      overlay.classList.add('active');

      // Après la fin de la transition (ici 500ms), on navigue vers le href
      setTimeout(() => {
        window.location.href = link.href;
      }, 3000);
    });
  });
}




main();