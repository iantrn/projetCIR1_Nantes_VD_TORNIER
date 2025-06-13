#include "main.h"


int main(void) {
    struct Text text; 
    readFile("book.txt", &text);
    for (int i = 1; i <= text.chapter_number; i++) {
        createFiles(&text, i); 
    }
    return 0;
}