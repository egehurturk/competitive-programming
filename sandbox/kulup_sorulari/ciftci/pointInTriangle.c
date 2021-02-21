#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

// compute the area of a triangle
float area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return fabs((float) (x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
}

bool checkIfInside(int x1, int x2, int x3, int y1, int y2, int y3, int kx, int ky) {
    float areaBigTri = area(x1, y1, x2, y2, x3, y3);
    float areaWith1Vertex = area(kx, ky, x2, y2, x3, y3);
    float areaWith2Vertex = area(x1, y1, kx, ky, x3, y3);
    float areaWith3Vertex = area(x1, y1, x2, y2, kx, ky);
    return (areaBigTri == areaWith1Vertex + areaWith2Vertex + areaWith3Vertex);
}

int main(void) {
    int x1, x2, x3, y1, y2, y3, kx, ky;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    scanf("%d %d", &kx, &ky);

    if (checkIfInside(x1,x2, x3, y1, y2, y3, kx, ky))
        printf("guvenli\n");
    else
        printf("guvensiz\n");
}
