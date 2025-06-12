#include "createfile.h"

void createFiles(struct Text* text, int chapters_number){
    for (int i = 1; i <= text->chapter_number; i++) { // on commence au chapitre 1
        char file_name[64];
        snprintf(file_name, 64, "%d.html", i);

        FILE *f = fopen(file_name, "w");
        if ( f == NULL) {
            printf("Erreur de lecture du chapitre : %d\n", i);
            exit(1);
        }

        const char* chapter_in_text = (const char*)text->chapters[i-1].text;
        fprintf(f, "%s", chapter_in_text);
        fclose(f);
    }
}

