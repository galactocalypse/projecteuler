/*
Mod 10^10.
Bruteforce.
That seriously worked?
*/
#include<stdio.h>
#include<math.h>
#define MOD 10000000000
long long get(int n){
	//n^n % 10^10
	int i;
	long long x = 1;
	for( i = 1; i<= n; i++)
		x = (x*n) % MOD;
	return x;
}
long long calc(int n){
	long long sum = 0;
	int i;
	for(i = 1; i <= n; i++){
		sum += get(i);
		sum %= MOD;
	}
	return sum;
}
int main(void){
	printf("%lld\n", calc(1000));
	return 0;
}
