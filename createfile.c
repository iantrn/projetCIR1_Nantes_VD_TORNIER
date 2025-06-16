#include "createfile.h"
#define MAX_CHOICES 3

void createFiles(struct Text* text, int chapter_id){
    mkdir("export", 0777); // création du dossier avec tous les droits dessus
    char file_name[64];
    snprintf(file_name, 64, "export/%d.html", chapter_id);
    char stylesheet[64] = "stylesheet";
    char css_file[64] = "../web/index.css";
    char js_file[64] = "../web/main.js";
    

    FILE *f = fopen(file_name, "w");
    if (f == NULL) {
         printf("Erreur de lecture du chapitre : %d\n", chapter_id);
        exit(1);
    }
    fprintf(f, "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\">\n<title>%s</title>\n<link rel=\"%s\" href=\"%s\">\n<script src=\"%s\" defer></script>\n",  text->chapters[chapter_id - 1].title, stylesheet, css_file, js_file);
    fprintf(f, "<link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">\n<link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>\n<link href=\"https://fonts.googleapis.com/css2?family=Jacquard+24&display=swap\" rel=\"stylesheet\">\n");
    fprintf(f, "<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.0/css/all.min.css\">\n");
    fprintf(f, "</head>\n<body>\n");
    fprintf(f, "<h1>%s</h1>\n", text->chapters[chapter_id - 1].title);
    fprintf(f, "<div class=\"content\">\n%s\n</div>\n",text->chapters[chapter_id - 1].content );
    for (int i = 0; i < MAX_CHOICES; i++) {
        int chapter_choice_id = text->chapters[chapter_id - 1].choices[i].choices_id;
        if ( chapter_choice_id > 0) {
            char *chapter_choice_content = text->chapters[chapter_id - 1].choices[i].choices_content;  
            fprintf(f, "<div class=\"choices\">\n<a href=\"%d.html\" class=\"choice\">%s</a>\n</div>\n", chapter_choice_id, chapter_choice_content);
            }
        continue;
        }
    fprintf(f, "<div id=\"overlay\"></div>\n");
    fprintf(f,"<audio id=\"background-audio\" src=\"../web/images/background_musique.mp3\" loop></audio>\n");
    fprintf(f,"<button id=\"sound_button\">\n<i class=\"fas fa-volume-up\"></i>\n</button>\n");
    fprintf(f, "</body>\n</html>\n");
        
    fclose(f);
    
}

