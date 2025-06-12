#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"
#define LINE_SIZE 512


struct Chapter {
    char chapter_title[256];
    int chapter_id;
    char *text;
    char choices;

};

struct Text {
    struct Chapter *chapters;
    int chapter_number;
};

struct Choice{
    char id_choice;
    char text_choice;
};


const char filename = "book.txt";

void readFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file <%s>\n", filename);
        exit(EXIT_FAILURE);
    }
    char line[LINE_SIZE];
    while (fgets(line, sizeof(line), file)) {

    }

}










