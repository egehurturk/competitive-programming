#include <stdio.h>
#include <string.h>
#include <stdint.h>



int main(int argc, char *argv[]) {
    // ./program path_to_img
    if (argc != 3) { 
        fprintf(stderr, "Usage: copy source destination.\n");
        return 1;
    }
    
    FILE *source = fopen(argv[1], "r");
    if (source == NULL) {
        printf("Could not open %s\n", argv[1]);
        return 1;
    }

    FILE *dest = fopen(argv[2], "w");
    if (dest == NULL) {
        fclose(source);
        printf("Could not create %s.\n", argv[2]);
        return 1;
    }

    uint8_t buffer;
    while (fread(&buffer, sizeof(uint8_t), 1, source)) {
        fwrite(&buffer, sizeof(uint8_t), 1, dest);
    }

    fclose(source);
    fclose(dest);
    return 0;
}