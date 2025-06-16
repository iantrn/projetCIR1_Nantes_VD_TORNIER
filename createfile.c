#include "createfile.h"

void createFiles(struct Text* text, int chapter_id){
    mkdir("export", 0777); // création du dossier avec tous les droits dessus
    char file_name[64];
    snprintf(file_name, 64, "export/%d.html", chapter_id);
    char stylesheet[64] = "stylesheet";
    char css_file[64] = "index.css";
    char js_file[64] = "main.js";
    

    FILE *f = fopen(file_name, "w");
    if (f == NULL) {
         printf("Erreur de lecture du chapitre : %d\n", chapter_id);
        exit(1);
    }
    fprintf(f, "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\">\n<title>%s</title>\n<link rel=\"%s\" href=\"%s\">\n<script src=\"%s\" defer></script>\n</head>\n<body>\n",  text->chapters[chapter_id - 1].title, stylesheet, css_file, js_file);
    fprintf(f, "<h1>%s</h1>\n", text->chapters[chapter_id - 1].title);
    fprintf(f, "%s\n",text->chapters[chapter_id - 1].content );
        //fprintf(f, "<div class=\"choices\">\n%s\n</div>\n", chapter_choices);
    
    fprintf(f, "</body>\n</html>\n");
        
    fclose(f);
    
}

