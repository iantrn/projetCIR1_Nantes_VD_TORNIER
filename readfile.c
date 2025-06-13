
#include "readfile.h"
#define LINE_SIZE 512

const char* filename = "book.txt";

void readFile(char* filename, struct Text* text) {

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file <%s>\n", filename);
        exit(EXIT_FAILURE);
    }

    struct Text* text = malloc(sizeof(struct Text));
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
    text->chapter_number=0;

    while(fgets(line, sizeof(line), file)) {
       
    }

}