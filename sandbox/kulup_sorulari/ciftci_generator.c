#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef struct input {
    int x1, x2, x3, y1, y2, y3, kx, ky;
} input;

float area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return fabs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
}

bool checkIfInside(input co) {
    float areaBigTri = area(co.x1, co.y1, co.x2, co.y2, co.x3, co.y3);
    float areaWith1Vertex = area(co.kx, co.ky, co.x2, co.y2, co.x3, co.y3);
    float areaWith2Vertex = area(co.x1, co.y1, co.kx, co.ky, co.x3, co.y3);
    float areaWith3Vertex = area(co.x1, co.y1, co.x2, co.y2, co.kx, co.ky);
    return (areaBigTri == areaWith1Vertex + areaWith2Vertex + areaWith3Vertex);
}



int main(void) {


    input i1;
    input i2;
    input i3;
    input i4;
    input i5;
    input i6;
    input i7;
    input i8;
    input i9;
    input i10;

    // yes
    i1.x1 = 2;
    i1.x2 = 4;
    i1.x3 = 3;
    i1.y1 = 1;
    i1.y2 = 1;
    i1.y3 = 2;
    i1.kx = 3;
    i1.ky = 1;

    // no
    i2.x1 = 987;
    i2.x2 = 105;
    i2.x3 = 600;
    i2.y1 = 4;
    i2.y2 = 2;
    i2.y3 = 403;
    i2.kx = 749;
    i2.ky = 379;

    // yes
    i3.x1 = 389;
    i3.x2 = 234;
    i3.x3 = 749;
    i3.y1 = 456;
    i3.y2 = 1460;
    i3.y3 = 379;
    i3.kx = 549;
    i3.ky = 490;

    // no
    i4.x1 = 984758;
    i4.x2 = 54627;
    i4.x3 = 7234;
    i4.y1 = 54273;
    i4.y2 = 42384;
    i4.y3 = 90589;
    i4.kx = 549;
    i4.ky = 1890;

    // yes
    i5.x1 = 28347;
    i5.x2 = 27834;
    i5.x3 = 7234;
    i5.y1 = 82384;
    i5.y2 = 12838;
    i5.y3 = 41283;
    i5.kx = 20000;
    i5.ky = 45000;

    // no   ---> weird input but ok
    i6.x1 = 1e6;
    i6.x2 = 1;
    i6.x3 = 500000;
    i6.y1 = 1e6;
    i6.y2 = 1;
    i6.y3 = 500000;
    i6.kx = 500000;
    i6.ky = 300000;

    // yes
    i7.x1 = 1;
    i7.x2 = 2;
    i7.x3 = 3;
    i7.y1 = 1;
    i7.y2 = 4;
    i7.y3 = 3;
    i7.kx = 2;
    i7.ky = 2;

    // no
    i8.x1 = 234938;
    i8.x2 = 92349;
    i8.x3 = 14;
    i8.y1 = 482398;
    i8.y2 = 324349;
    i8.y3 = 19;
    i8.kx = 2;
    i8.ky = 2;

    // yes
    i9.x1 = 999999;
    i9.x2 = 999990;
    i9.x3 = 999998;
    i9.y1 = 999999;
    i9.y2 = 999995;
    i9.y3 = 999997;
    i9.kx = 999996;
    i9.ky = 999997;

    // yes
    i10.x1 = 1238;
    i10.x2 = 4832;
    i10.x3 = 9182;
    i10.y1 = 3482;
    i10.y2 = 4328;
    i10.y3 = 2394;
    i10.kx = 5000;
    i10.ky = 3600;

    input testCases[10]= { 
        i1, i2, i3, i4, i5, i6, i7, i8, i9, i10
    };

    for (int i = 1; i <= ( sizeof(testCases) / sizeof(testCases[0]) ); i++) {
        char* inputName = (char*) malloc(27 * sizeof(char));
        char* outputName = (char*) malloc(28 * sizeof(char));

        sprintf(inputName, "%s%d%s", "ciftci/input", i, ".txt");
        sprintf(outputName, "%s%d%s", "ciftci/output", i, ".txt");

        FILE *fin = fopen(inputName, "w");
        FILE *fout = fopen(outputName, "w");
        // write to input file
        fprintf(fin, "%d %d\n%d %d\n%d %d\n%d %d\n", testCases[i-1].x1, testCases[i-1].y1, testCases[i-1].x2, testCases[i-1].y2, testCases[i-1].x3, testCases[i-1].y3, testCases[i-1].kx, testCases[i-1].ky);

        // output generation
        
        int inside = checkIfInside(testCases[i-1]);
        printf("%d\n", inside);
        // check 
        if (inside) {
            fprintf(fout, "guvenli\n");
        } else {
            fprintf(fout, "guvensiz\n");
        }
       
        
        // free
        free(inputName);
        free(outputName);
        fclose(fin);
        fclose(fout);
    }
}