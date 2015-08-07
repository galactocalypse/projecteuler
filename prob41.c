/*
Alright, I thought a simple search would do.
Forgot I don't have all primes upto 10^9 stored.
Had to do this by checking 9, 8, 7 digit pandigital numbers individually.
Even had to break the 9 digit ones into sections of 10^8 so they could run on ideone.

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
int bsearch(int l, int r, int s){
	int m = (l+r)/2;
	if(primes[m] == s)return m;
	if(l>=r)return -1;
	if(primes[m] < s)return bsearch(m+1, r, s);
	return bsearch(l, m, s);
}
int isPrime(int n){
	return (bsearch(0, np-1, n) >= 0);
}
int checkNum(int n){
	int arr[10] = {0};
	int i = 0;
	while(n){
		arr[n%10]++;
		n /= 10;
		i++;
	}
	while(i)
		if(arr[i--]!=1)return 0;
	return 1;
}
int main(void)
{
    int i, sum = 0, c = 0, f, j;
	populate();
	for( i = 87654321 ; i >= 1234567; i -= 2 ){
		if(!checkNum(i))continue;
		f = 1;
		for( j = 0; primes[j]*primes[j] <= i; j++ ){
			if( i % primes[j] == 0){
				f = 0;
				break;
			}
		}
		if(f){
			c = i;
			break;
		}
	}
	
	if(!c)
	for( i = np - 1  ; i >= 0 ; i-- ){
		if(checkNum(primes[i])){
			c = primes[i];
			break;
		}
	}
	
	printf("%d", c);
	return 0;
}
