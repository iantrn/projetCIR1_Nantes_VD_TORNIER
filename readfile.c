#include <readfile.h>

#define LINE_SIZE 512

int main(void) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file <%s>\n", filename);
        exit(EXIT_FAILURE);
}

    char line[LINE_SIZE];
    while(fgets(line, sizeof(line), file)) {
    // ...
}
}





