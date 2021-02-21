#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float power(int base, int power) {
    float result = 1;
    for (int i = 0; i < power; i++) {
        result *= base;
    }
    return result;
}

int armstrong(int num) {
    int originalNum = num, remainder, n = 0;
    float result = 0.0;
    while (originalNum != 0) {
        n++;
        originalNum /= 10;
    }
    originalNum = num;
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += power(remainder, n);
        originalNum /= 10;
    }
    return result;
}

int testCases[] = { 
    153, 370, 371, 6437, 407, 876, 0, 9474, 1, 8208, 10000, 9999, 2
};


int main(void) {

    for (int i = 0; i < ( sizeof(testCases) / sizeof(testCases[0])); i++) {
        char* inputName = (char*) malloc(27 * sizeof(char));
        char* outputName = (char*) malloc(28 * sizeof(char));

        sprintf(inputName, "%s%d%s", "armstrongProblem/input", i, ".txt");
        sprintf(outputName, "%s%d%s", "armstrongProblem/output", i, ".txt");

        FILE *fin = fopen(inputName, "w");
        FILE *fout = fopen(outputName, "w");
        // write to input file
        fprintf(fin, "%d\n", testCases[i]);

        // output generation
        int res = armstrong(testCases[i]);

        // check 
        if (res == testCases[i]) {
            fprintf(fout, "Evet\n");
        } else {
            fprintf(fout, "Hayir\n");
        }
        // free
        free(inputName);
        free(outputName);
        fclose(fin);
        fclose(fout);
    }
}