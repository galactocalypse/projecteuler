#include<stdio.h>
#include<math.h>

#define MAX 2000000
int primes[1000000];
int np;

void populate()
{
    int d, i, j, lim, isp;
    np = 0;
    d = 4;
    primes[np++] = 2;
    primes[np++] = 3;
    primes[np++] = 5;
    primes[np++] = 7;
    for (i = 11; i < MAX; i += d) {

	lim = (int) ceil(sqrt(i));
	isp = 1;
	for (j = 0; primes[j] <= lim; j++) {
	    if (i % primes[j] == 0) {
		isp = 0;
		break;
	    }
	}
	if (isp)
	    primes[np++] = i;
	d = 6 - d;
    }

}

int main(void)
{
    int t, m, n, lim, isp, i, j, d;
	populate();
	long long sum = 0;
	for( i = 0 ; i < np ; i++ ){
		sum += primes[i];
	}
	printf("%llu", sum);
    return 0;
}
