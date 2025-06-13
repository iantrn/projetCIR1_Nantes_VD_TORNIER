#include "createfile.h"

void createFiles(struct Text* text, int chapter_id){
    mkdir("export", 0777); // création du dossier avec tous les droits dessus
    char file_name[64];
    snprintf(file_name, 64, "export/%d.html", chapter_id);

    FILE *f = fopen(file_name, "w");
    if (f == NULL) {
         printf("Erreur de lecture du chapitre : %d\n", chapter_id);
        exit(1);
    }
    fprintf(f, "<!DOCTYPE html>\n<html>\n<head><meta charset=\"UTF-8\"><title>%s</title></head>\n<body>\n",  text->chapters[chapter_id - 1].title);
    fprintf(f, "<h1>%s</h1>\n", text->chapters[chapter_id - 1].title);
    fprintf(f, "%s\n",text->chapters[chapter_id - 1].content );
        //fprintf(f, "<div class=\"choices\">\n%s\n</div>\n", chapter_choices);
        //fprintf(f, "</body>\n</html>\n");
        
    fclose(f);
    
}

