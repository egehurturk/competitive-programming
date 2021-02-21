#include <iostream>

int main(void)
{
    int T, a, b, x, y;
   
    while (scanf("%d", &T) == 1 && T)
    {
        scanf("%d %d", &a, &b); // coordinates of division
        while (T--)
        {
            scanf("%d %d", &x, &y); // coordinates

            int dist_orX = x - a;
            int dist_orY = y - b;

            if (dist_orX > 0 && dist_orY > 0)
                printf("NE\n");

            else if (dist_orX > 0 && dist_orY < 0)
                printf("SE\n");

            else if (dist_orX < 0 && dist_orY > 0)
                printf("NO\n");

            else if (dist_orX < 0 && dist_orY < 0)
                printf("SO\n");

            else if (dist_orX == 0|| dist_orY == 0)
                printf("divisa\n");
        
        }

    }
}