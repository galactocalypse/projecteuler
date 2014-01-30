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
int isPrime(int n){
	int i=0;
	if( n < 0 )return isPrime(-n);
	while(i < np && n >= primes[i]){
		if(primes[i] == n)return 1;
		i++;
	}
	return 0;
}
int main(void)
{
    int t, m, n, lim, isp, x, i, j, d, a, b, max=0, maxp;
	populate();
	
	//printf("%d %d : %d\n", a, b, n);
	x = 0;
	for(a = -999; a<=1000;a+=2){
		for(b=0; primes[b]<=1000; b++){
			if(b%2 == 0)x=1;else x=0;
			n = 0;
			while(isPrime(n*n + (a-x)*n + primes[b])){n++;}
			if(n > max){
				max = n;
				maxp = (a-x)*primes[b];
				//printf("%d %d : %d\n", a-x, primes[b], max);
			}
			n = 0;
			while(isPrime(n*n+(a-x)*n-primes[b])){n++;}
			//printf("%d %d : %d\n", a, b, n);
			if(n > max){
				max = n;
				maxp = (a-x)*primes[b];
				//printf("%d %d : %d\n", a-x, primes[b], max);
			}
		}
	}
	printf("%d\n", maxp);
    return 0;
}
