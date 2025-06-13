#ifndef READFILE_H 
#define READFILE_H 



#include <stdio.h>     
#include <stdlib.h>
#include <string.h>

struct Chapter {
    char id[16];
    char title[256];
    char content[4096];
};

struct Text {
    struct Chapter *chapters;
    int chapter_number;
};


void readFile(char* filename, struct Text* text);

#endif