#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"
#define LINE_SIZE 512


const char filename = "book.txt";

void readFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file <%s>\n", filename);
        exit(EXIT_FAILURE);
    }
    char line[LINE_SIZE];
    while(fgets(line, sizeof(line), file)) {

    }

}

void GetChapter(char* line, struct Chapter *chapter){
    FILE* file = fopen(filename, "r");
    int idChapter;
    char title[256];
    char lines[LINE_SIZE];
    while(fgets(lines, sizeof(lines), file)) {
        if(strstr(lines,"<chapter") != NULL){
            sscanf(line, "<chapter id=\"%d\">%[^<]</chapter>", &idChapter, title);
            chapter->chapter_title = title;
            chapter->chapter_id = idChapter;
            printf("%s,%d",chapter->chapter_title, chapter->chapter_id);
        };
    }; 
};
