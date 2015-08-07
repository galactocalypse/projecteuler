#include<stdio.h>
#include<math.h>

#define ll long long

int isPal(int n){
	if( n / 100000 == n % 10 ){
		n = n % 100000;
		if( n / 10000 == ( n % 100 ) / 10 ){
			n = n % 10000;
			if( n / 1000 == ( n % 1000 ) / 100 ){
				return 1;
			}
		}
	}
	return 0;
}
int main(void){
	int i, j, res = 0;
	for( i = 999 ; i >= 901 ; i-- ){
		for( j = 999 ; j >= 901; j-- ){
			if(isPal(i*j)){
				res = i*j;
				break;
			}
		}
		if(res)break;
	}
	printf("%d", res);
	return 0;
}
