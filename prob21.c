#include<stdio.h>
#define MAX 10000
int primes[10001] = {0};
int np = 0;

void populate(){
	int i=0, j;
	int f;
	np = 0;
	primes[np++]  = 2;
	primes[np++]  = 3;
	primes[np++]  = 5;
	primes[np++]  = 7;
	primes[np++]  = 11;
	
	for( i = 13 ; i <= MAX ; i++ ){
		f = 1;
		for( j = 0; primes[j]*primes[j] <= i; j++ ){
			if( i % primes[j] == 0){ f = 0; break;}
		}
		if(f == 1)primes[np++] = i;
	}
}
int getSum(int n){
	int sum = 1;
	int i, t, fac, s;
	for(i = 0; primes[i] <= n/2; i++ ){
		t = n;
		fac = primes[i];
		s = 1;
		while(t%primes[i] == 0 && t > 1){
			t/=primes[i];
			s+=fac;
			fac*=primes[i];
		}
		sum*=s;
	}
	if(sum > n)sum-=n;
	return sum;
}
int main(void){
	int i;
	int arr[10001] = {0};
	long long s = 0;
	populate();
	for( i = 1; i <= 10000 ; i++ ){
		arr[i] = getSum(i);
	}
	for( i = 1 ; i <= 10000 ; i++ ){
		if(arr[i] < 10001)
			if(arr[arr[i]] == i && i!=arr[i])
				s+= i;
	}

	printf("%lld", s);
	return 0;
}
