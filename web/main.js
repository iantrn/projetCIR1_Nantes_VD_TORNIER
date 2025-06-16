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
            }, 1500);
        }, 1500);
    });
  });
}




main();