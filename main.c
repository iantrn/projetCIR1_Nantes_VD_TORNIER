#include "main.h"


int main(void) {
    struct Text text; 
    readFile("book.txt", &text);
    for (int i = 0; i < text.chapter_number; i++) {
        createFiles(&text, 10); 
    }
   
    free(text.chapters);
    return 0;
}