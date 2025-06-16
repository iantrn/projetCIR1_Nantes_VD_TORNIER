function main() {
    function choices_animations() {
        const fade = document.getElementById('fade');
        const choicesDiv = document.querySelector('.choices');

        choicesDiv.addEventListener('click', (event) => {
        const target = event.target;
        if (target.tagName === 'A') {
            event.preventDefault();

            const url = target.href;

            fade.style.pointerEvents = 'auto';
            fade.style.opacity = '1';

            setTimeout(() => {
            window.location.href = url;
            }, 1000);
        }
    });
  }
    let choices_animation = document.getElementsByClassName("choices");



}






main();