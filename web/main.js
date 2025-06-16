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
    audio.play().catch(err => {
      console.warn("Lecture automatique bloquée. L'utilisateur doit interagir.");
    });
  }
  window.addEventListener('DOMContentLoaded', backgroundMusic);



}




main();