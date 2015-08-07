#include<stdio.h>
int checkBoolPalin(int n){
	int arr[32]={0};
	int i = 0;
	if(n==0)return 0;
	while(n){
		arr[i++] = n&1;
		n=n>>1;
	}
	while(arr[i-1] == 0)i--;
	n = i;
	for(i = 0; i<n/2; i++){
		if(arr[i]!=arr[n-i-1])return 0;
	}
	return 1;
}
int checkPalin(int n){
	int arr[7]={0};
	int i = 0;
	while(n){
		arr[i++] = n%10;
		n=n/10;
	}
	n = i;
	for(i=0;i<n/2;i++)
		if(arr[i]!=arr[n-1-i])return 0;
	return 1;
}
int rev(int n){
	int x = 0;
	while(n){
		x = x*10+n%10;
		n=n/10;
	}
	return x;
}
int main(void){
	int i;
	long long sum = 0;
	for(i=1;i<1000000;i++){
		if(checkPalin(i) && checkBoolPalin(i))sum+=i;
	}
	printf("%lld", sum);
	return 0;
}
