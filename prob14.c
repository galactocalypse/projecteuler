#include<stdio.h>
int arr[1000001] = {};
int getNum( long long i){
	long long	x = i;
	int c = 0;
	if( i < 2)return arr[i];
	if( i < 1000001 && arr[i] )return arr[i];
	while( x > 1000000 || !arr[x]){
		if(x&1){
			x = x*3 + 1;
		}
		else x = x >> 1;
		c++;
	}
	return c + getNum(x);
}
void populate(){
	int i;
	arr[0] = 0;
	arr[1] = 1;
	for( i = 2 ; i <= 1000000 ; i++ ){
		arr[i] = getNum(i);
	}
}
int main(void){
	int i, max = 0;
	populate();
	for( i = 1 ; i < 1000001 ; i++ )
		if(arr[i] > arr[max]) max = i;
	printf("%d", max);
	return 0;
}