
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
    int id = 0;

    while(fgets(line, sizeof(line), file)) {
        if (strstr(line,"<chapter")) {  
            id++;          
            current = &text->chapters[id - 1];
            current->content[0] = '\0';
            sscanf(line, "<chapter id=\"%d\">%[^<]s</chapter>", &id, current->title);
            printf("%s", current->title);
        }
        if (strstr(line,"<p")) {     
            strncat(text->chapters[id-1].content, line, 2048);
        }
        if (strstr(line,"<choice")) {

        } 


        
    }
    text->chapter_number = id + 1;
    fclose(file);
    
}



