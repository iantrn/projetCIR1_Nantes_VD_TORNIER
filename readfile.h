#include <stdio.h>     
#include <stdlib.h>
#include <string.h>

struct Chapter {
    char *id;
    char *title;
    char* content;
};

struct Text {
    struct Chapter *chapters;
    int chapter_number;
};


void readFile(char* filename, struct Text* text);