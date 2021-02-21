#include <stdio.h>
#define SUCC 0
#define FAIL 1

char risp[2][8] = { "success\0" , "failure\0" };

int main() {
	int H, D, U, F;
	int t, i;
	double d, dp, h;

	scanf("%d %d %d %d", &H, &U, &D, &F);
	while(H != 0) {
		d = U;
		dp = (double)U * F / 100;
		for(t=1, h=0; ; t++) {
			/* Sun */
			h += d;
			if(h > H) {
                i = SUCC;
                break;
            }

            /* night */
            h -= D;
            if(h < 0) {
                i = FAIL;
                break;
            }

            /* affaticamento */
            d -= dp;
            if(d < 0)
                d = 0;
		}

		printf("%s on day %d\n", risp[i], t);
		scanf("%d %d %d %d", &H, &U, &D, &F);
	}
	return 0;
}