/*
Looks straightforward, unless the answer is greater than 2000000.
Oops. Miscalculated. Might take long.

Didn't take long. Smallish number for an answer.
Read the formula mentioned in the question wrong.

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
int isSq(int x){
	double s = sqrt(x);
	return (ceil(s) == floor(s));
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
int checkNum(int n){
	int i;
	for(i = 0; i < np && primes[i] < n; i++){
		if(isSq((n - primes[i])/2))return 0;
	}
	return 1;
}

int main(void){
    int i, sum = 0, c = 0, f, j;
	populate();
	for( i = 35; i <= 2000000; i+=2)
		if(!isPrime(i))
			if(checkNum(i))
				break;
	printf("%d", i);
	return 0;
}
