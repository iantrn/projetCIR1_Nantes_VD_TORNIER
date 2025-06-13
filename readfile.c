
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
    int chapter_index = -1;

    while(fgets(line, sizeof(line), file)) {
        if (strstr(line,"<chapter")) {
            chapter_index++;
            text->chapters[chapter_index].content[0] = '\0';
            char* title_start = strchr(line, '>');
            char* title_end = strstr(line, "</chapter>");
            if (title_start && title_end) {
                title_start++; // on passe le '>'
                int title_len = title_end - title_start;
                strncpy(current->title, title_start, title_len);
            }

        }
        if (chapter_index >= 0) {
            strncat(text->chapters[chapter_index].content, line, 2048);
        }
    }
    text->chapter_number = chapter_index + 1;
    fclose(file);
}


