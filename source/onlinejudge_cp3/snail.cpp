#include <iostream>

#define DEBUG 0


#define LOG_i(X) (printf("%d\n", X))
#define LOG_f(X) (printf("%f\n", X))
#define LOG_c(X) (printf("%c\n", X))


using namespace std;

int main(void)
{
    int H,U,D,F;
    while (scanf("%d %d %d %d", &H, &U, &D, &F) == 4 && H)
    {
        int day = 1;
        float height = 0;
        
        while (height < H)
        {
#if DEBUG == 1
    LOG_i(day);
    LOG_f(height);
#endif 
            if (day == 1) {
                // height = U-D;
                if (U > H) {printf("success on day 1\n"); break; }

                height = (U-D < 0) ? -1 : U-D; // 2 1 1 1 || 11 1 87 42
#if DEBUG == 1
    LOG_f(height);
#endif
                if (height < 0)
                {
                    printf("failure on day 1\n");
                    break;
                }
            }

            else
            {
                float percentage =  U * (F / 100.0); // Fatigue Factor
#if DEBUG == 1
    LOG_f(percentage);
#endif
                float distance = U - ((day-1) * percentage); // Distance climbed
#if DEBUG == 1
    LOG_f(distance);
#endif
                if (distance < 0) distance = 0;
                height += distance; // Height after climbing 
#if DEBUG == 1
    LOG_f(height);
#endif
                if (height > H)
                {
                    printf("success on day %d\n", day);
                    break;
                }
                height -= D; // Height after sliding (1)
#if DEBUG == 1
                    LOG_f(height);
#endif
                if (height < 0)
                {
                    printf("failure on day %d\n", day);
                    break;
                }
            }
            day++;
        }
    }
}

// Passes Judge, but throws a few WA on some extreme cases. Anyway, good work. 