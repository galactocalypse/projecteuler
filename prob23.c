#include<stdio.h>
#define MAX 28123
int primes[MAX+1] = {0};
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
int getSum(int n){//sum of divisors
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
	int i, j;
	int arr[MAX+1] = {0};
	int a[6965] = {0};
	int nums[MAX]={0};
	int ptr=0;
	long long s = 0;
	populate();
	for( i = 1; i <= MAX ; i++ ){
		arr[i] = getSum(i);
	}
	s = 0;
	for(i=0;i<MAX; i++)
		if(arr[i] > i)a[ptr++]=i;
	for(i=0;i<ptr-1; i++){
		for(j=i;j<ptr;j++)
			nums[a[i]+a[j]] = 1;
	}
	s = 0;
	for(i=0;i<MAX; i++){
		if(nums[i] == 0)s+=i;
	}
	printf("%lld", s);
	return 0;
}
