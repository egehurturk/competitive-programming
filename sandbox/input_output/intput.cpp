#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
// verdigin sayinin ikiye bolunup bolunmedigi

int main(void)
{   
   int number;

   while (cin >> number)
   {
       printf(number & 1 ? "FALSE" : "TRUE");

       // printf nin ozellikleri:
       printf("%.4f\n", 329424.2343); // yuvarliyor
       printf("%.3f\n", 324.00); // istedigin kadar 0 koyuyor
       printf("%5d\n", 889); // 5 bosluk ekliyor
   }

   // string input
    string str; // string library, bunun icin string header i yap
   // usttekinin yerine char pointer kullan

    // %c kullanma, kullanirsan dikkat et
    char each;
   while (scanf("%c", &each) && each != 'Z')
   {
       if (each != '\n')
            printf("%c\n", each);
   }

}

