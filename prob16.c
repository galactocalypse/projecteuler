#include<stdio.h>
#include<math.h>
int main(void){
	int arr[302] = {0};
	int sum;
	int d = 302;
	int i, f = 0, p = 0, c = 0, j;
	for( i = 0; i < d ; i++){
		arr[i] = 0;
	}
	arr[0] = 1;
	
	for( p = 1; p<=1000; p++){
		c = 0;
		for( j = 0; j < d ; j++ ){
			arr[j] = c + arr[j]*2;
			c = arr[j]/10;
			arr[j] %= 10;
			if( !c && j >= f)break;
		}
		if( j > f) f = j;
	}
	sum = 0;
	for ( i = 0; i <= f ; i++ )
		sum += arr[i];
	printf("%d", sum);
	return 0;
}