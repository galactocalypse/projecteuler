/*
This one looks pretty darn easy. Not sure if insight is evem required.
Checking for digits is of the order of O(log10(N)).
Shouldn't hurt much for numbers < 10^8.
Let's see.

A bit of insight before we begin. Since 1x - 6x have the same digits, 6x should be less than the power of 10 just greater than 1x.
Hence, in the range 10^(x-1) - (10^x - 1) [x digits] : we have floor(10^x / 6) numbers to check.

Correct answer in no time!
*/
#include<stdio.h>
#include<math.h>
int compareDigs(int n, int m){
	int arr[10] = {0};
	int i;
	while(n){
		arr[n%10]++;
		n /= 10;
	}
	while(m){
		arr[m%10]--;
		m /= 10;
	}
	for( i = 0; i <= 9; i++)
		if(arr[i])return 0;
	return 1;
}
int check(int p){
	int i, k;
	int lim = floor(pow(10, p)/6);
	for( i = pow(10, p-1); i <= lim; i++){
		for(k = 2; k <= 6; k++)
			if(!compareDigs(i, i*k))break;
		if(k == 7)return i;
	}
	return 0;
}
int main(void){
	int c = 0;
	int i;
	for( i = 0; i <= 6; i++)
		if(c = check(i))break;
	printf("%d", c);
	return 0;
}
