#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    uint8_t pixel;
} GRAYSCLSINGLETON;

typedef struct {
    uint8_t rgbtBlue;
    uint8_t rgbtGreen;
    uint8_t rgbtRed;
} RGBTRIPLE;

void initialize_to_zero(int array[], int n) {
    for (int i = 0; i < n; i++) 
        array[i] = 0;
}

/* cap_pixel: normalize the byte according to its value based on the pixel classes */
void cap_pixel(GRAYSCLSINGLETON *byte, int s, int classes[], int nclasses) {
    int class_category = floor(byte->pixel / s + 1) - 1;
    if (class_category >= nclasses) {
        fprintf(stderr, "Something's wrong.\n");
    }
    classes[class_category]++;
    int range_start = (class_category + 1) * s, range_end = (class_category) * s;
    if (range_end > 255)
        range_end = 255;
    int avg_val = (range_start + range_end) / 2;
    byte->pixel = avg_val;
}

int main(int argc, char *argv[]) {

    if (argc != 4) { 
        fprintf(stderr, "Usage: copy source destination.\n");
        return 1;
    }
    
    int s = atoi(argv[3]);
    int numClass = ceil(255.0 / s);
    printf("total # of classes: %d\n", numClass);
    int CLASS[numClass];
    initialize_to_zero(CLASS, numClass);

    FILE *source = fopen(argv[1], "r");
    if (source == NULL) {
        printf("Could not open %s\n", argv[1]);
        return 1;
    }
    // check output
    FILE *dest = fopen(argv[2], "w");
    if (dest == NULL) {
        fclose(source);
        printf("Could not create %s.\n", argv[2]);
        return 1;
    }

    int total_pixels = 0;
    GRAYSCLSINGLETON buffer;
    while (fread(&buffer, sizeof(GRAYSCLSINGLETON), 1, source)) {
        cap_pixel(&buffer, atoi(argv[3]), CLASS, numClass);
        printf("%d\n", buffer.pixel);
        fwrite(&buffer, sizeof(GRAYSCLSINGLETON), 1, dest);
        total_pixels++;
    }

    printf("total pixels: %d\n", total_pixels);
    fclose(source);
    fclose(dest);

    for (int i = 0; i < numClass; i++)
        printf("class #%d (%d, %d): %d\n", i+1, (i) * s, (i+1)*s - 1, CLASS[i]);
    return 0;
}