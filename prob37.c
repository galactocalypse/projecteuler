/*
I still don't get the Maths behind this.
I merely tried to see if all the eleven primes were contained within 1000000.
Would like to know how to find an upper limit here. Can't always be guessing.
*/

#include<stdio.h>
#include<math.h>

#define MAX 1000000
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
	int i, t = n, m = 1;
	while(t){
		if(!isPrime(t))return 0;
		t/=10;
		m*=10;
	}
	m/=10;
	while(n){
		if(!isPrime(n))return 0;
		n%=m;
		m/=10;
	}
	return 1;
}
int main(void)
{
    int t, m, n, lim, isp, i, j, sum = 0, d, c = 0;
	populate();
	i = 0;
	while(primes[i]<10)i++;
	for(  ; i < np ; i++ ){
		if(checkNum(primes[i])){
			c++;
			sum+=primes[i];
			//printf("%d\n", primes[i]);
		}
	}
	//printf("%d\n", c);
	printf("%d", sum);
	return 0;
}
