
#include "readfile.h"
#define LINE_SIZE 512

const char* filename = "book.txt";

void readFile(char* filename, struct Text* text) {

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file <%s>\n", filename);
        exit(EXIT_FAILURE);
    }
    
    if (text == NULL) {
        printf("Malloc error");
        exit(EXIT_FAILURE);
    }

    text->chapters = malloc(10*sizeof(struct Chapter));
    if (text->chapters == NULL) {
        printf("Malloc error");
        exit(EXIT_FAILURE);
    }
 
    char line[LINE_SIZE];
    struct Chapter* current; 
    text->chapter_number = 0;

    while(fgets(line, sizeof(line), file)) {
      // Début de chapitre
        if (strstr(line, "<chapter") != NULL) {
            current = &text->chapters[text->chapter_number];
            current->content[0] = '\0';

            // Extraire l'id
            char* id_start = strstr(line, "id=\"");
            if (id_start) {
                id_start += 4;
                char* id_end = strchr(id_start, '"');
                if (id_end) *id_end = '\0';
                strncpy(current->id, id_start, sizeof(current->id));
            }

            // Extraire le titre (après '>')
            char* title_start = strchr(line, '>');
            if (title_start) {
                title_start++;
                char* title_end = strstr(title_start, "</chapter>");
                if (title_end) *title_end = '\0';
                strncpy(current->title, title_start, sizeof(current->title));
            }

            text->chapter_number++;
        }
        // Paragraphes, choix, etc. (contenu)
        else if (current != NULL) {
            strncat(current->content, line, 2048);
        }
    }
    fclose(file);
}