#include "readfile.h"
#define LINE_SIZE 512


struct Chapter {
    char chapter_title[256];
    int chapter_id;
    char text[256];
    char *choices;

};



const char* filename = "book.txt";

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
    


