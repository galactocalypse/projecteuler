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
int getPow(long long a, long long b){
	if(a % b == 0)return 1 + getPow(a/b, b);
	return 0;
}
int main(void)
{
	long long N = 10000;
	long long off = 4000;
	long long step = 1;
    long long n, i, c, cc, j, x, t;
	populate();
	for( i = off+1; i <= off+N; i+=step){
		c = 1;
		t = i*(i+1)/2;
		j = 0;
		cc = t;
		while(t > 1){
			x = 0;
			while(t % primes[j] == 0){
				x++;
				t /= primes[j];
			}
			c *= (x+1);
			j++;
		}
		if(c >= 500){
			printf("%lld: %lld: %lld\n", i, cc, c);
			break;
		}
		
	}
	

	return 0;
}