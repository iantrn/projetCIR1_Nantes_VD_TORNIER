#include <stdio.h>     
#include <stdlib.h>
#include <string.h>

struct Choice{
    int id_choice;
    char *text_choice;
};

struct Chapter {
    char chapter_title[256];
    int chapter_id;
    char *text;
    struct Choice* choices;

};

struct Text {
    struct Chapter *chapters;
    int chapter_number;
};

void GetChapter(struct Chapter *chapter, char* line);

void readFile(char* filename);