#include <iostream>

int main(void)
{
    float months, down_pay, loan, dep_rec, dep_per, car, own, pay_per_mon;
    int mn, mon=0;
    while (scanf("%f %f %f %f", &months, &down_pay, &loan, &dep_rec) == 1 && months)
    {
        own = loan;
        car = loan + down_pay;
        pay_per_mon = loan / months;
        while (dep_rec--)
        {
            scanf("%d %f", &mn, &dep_per);
            while (own > car)
            {  
                own -= down_rec;
                car *= (1 - dep_per);
                mon++;
            }
            if (mon > 1)
            {
                printf("%d months\n", mon);
                return 1;
            }
            printf("%d month\n", mon);

        }
        mo--;
    }
    
   

}
