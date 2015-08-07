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
int nodig(int n){
	int d = 0;
	while(n){d++;n/=10;}
	return d;
}
int rot(int n, int d){
	int arr[10] = {0};
	int i, x=0;
	for(i=d; i>0 ; i--){
		arr[i-1] = n%10;
		n=n/10;
	}
	for(i=1; i<d;i++)
		x=x*10+arr[i];
	x=x*10+arr[0];
	return x;
}
int checkNum(int n){
	int rots = nodig(n) - 1;
	int i;
	if(!isPrime(n))return 0;
	for(i=0;i<rots;i++){
		n = rot(n,rots+1) ;
		if(!isPrime(n))return 0;
	}
	return 1;
}
int main(void)
{
    int t, m, n, lim, isp, i, j, d, c = 0;
	populate();
	
	for( i = 0 ; i < np ; i++ ){
		if(checkNum(primes[i])){
			c++;
			//printf("%d\n", primes[i]);
		}
	}
	printf("%d", c);
    
	return 0;
}
