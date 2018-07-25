#include <stdlib.h>
#include <stdio.h>

char buffer[10 * 1024];

int main(void) {
    fread(buffer, sizeof(char), sizeof(buffer), stdin);
    if (ferror(stdin)) {
        perror("Error reading from stdin");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
