#include <iostream>

int main(void)
{
    float down_pay, loan, dec_p[101]; // array is required when decreipt records do have seperate months
    int mon_loan, dep_rec;

    while (true)
    {
        scanf("%d %f %f %d", &mon_loan, &down_pay, &loan, &dep_rec);

        if (mon_loan < 0)
        {
            break;
        }

        int m;
        float per;
        while (dep_rec--)
        {
            scanf("%d %f", &m, &per);
            for(int i = m; i < 101; ++i)
            {
                dec_p[i] = per;
            }
        }
        int months = 0; // ans
        float car, own, payment_monthly;
        car = (loan + down_pay) * (1 - dec_p[0]); // initial value of car
        payment_monthly = loan / mon_loan; 
        own = loan; // your money
        while (car < own)
        {
            months++;
            own -= payment_monthly;
            car *= (1 - dec_p[months]); // decrease the car value by percentage
            
        }
        printf("%d month", months);
        if (months != 1)
        {
            printf("s");
        }
        printf("\n");

    }
}