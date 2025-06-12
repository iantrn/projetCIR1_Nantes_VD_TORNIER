
#include "readfile.h"
#define LINE_SIZE 512


const char* filename = "book.txt";


/*struct Chapter getChapter(int index){
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
};*/


void readFile(char* filename) {

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
    text->chapter_number = 10;    
    char line[LINE_SIZE];
    while(fgets(line, sizeof(line), file)) {
        for (int i = 1; i <= 10; i++) {
            
        }
    }

}