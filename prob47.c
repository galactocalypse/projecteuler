/*
Factorize.
*/
/*
Looks straightforward, unless the answer is greater than 2000000.
Oops. Miscalculated. Might take long.

Didn't take long. Smallish number for an answer.
Read the formula mentioned in the question wrong.

Alright, not all prime factors are contained within sqrt(n).

*/
#include<stdio.h>
#include<math.h>

#define MAX 2000000
int primes[500000];
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
int binsearch(int *arr, int l, int r, int s){
	int m = (l+r)/2;
	if(arr[m] == s)return m;
	if(l >= r)return -1;
	if(s < arr[m])return binsearch(arr, l, m, s);
	return binsearch(arr, m+1, r, s);
}
int isPrime(int n){
	return binsearch(primes, 0, np-1, n) != -1;
}

int main(void){
    int i, sum = 0, c = 0, f, j, t, ans, div;
	populate();
	for( i = 645; i <= MAX; i++){
		f = 0;
		t = i;
		for(j = 0; j < np; j++ ){
			div = 0;
			while( t%primes[j] == 0 && t > 1){
				t /= primes[j];
				div = 1;
			}
			if(div)f++;
			if(t == 1)break;
		}
		if(f == 4)c++;
		else c = 0;
		if(c == 4){
			ans = i - 3;
			break;
		}
	}
	printf("%d", ans);
	return 0;
}
