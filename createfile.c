#include "createfile.h"

void createFiles(struct Text* text, int chapters_number){
    mkdir("export", 0777); // création du dossier avec tous les droits dessus
    for (int i = 1; i <= 10; i++) { // on commence au chapitre 1
        char file_name[64];
        snprintf(file_name, 64, "export/%d.html", i);

        FILE *f = fopen(file_name, "w");
        if (f == NULL) {
            printf("Erreur de lecture du chapitre : %d\n", i);
            exit(1);
        }
        const char* chapter_title = (const char*)text->chapters[i-1].title;
        
        const char* chapter_in_text = (const char*)text->chapters[i-1].content;
        
        //const char* chapter_choices = (const char*)text->chapters[i-1].choices;
        
        //fprintf(f, "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\"><title>%s</title></head>\n<body>\n", chapter_title);
        fprintf(f, "<h1>%s</h1>\n", chapter_title);
        fprintf(f, "%s\n", chapter_in_text);
        //fprintf(f, "<div class=\"choices\">\n%s\n</div>\n", chapter_choices);
        //fprintf(f, "</body>\n</html>\n");
        
        fclose(f);
    }
}

