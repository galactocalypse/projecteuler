#include<stdio.h>
int main(void){
	int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int x = 1, c = 0, i, j;
	for ( i = 1 ; i <= 100 ; i++ ){
		for( j = 0 ; j < 12 ; j++ ){
			x = ( x + arr[j] + (i%4 == 0 && j==1 )) % 7;
			c += (x == 6);
		}
	}
	printf("%d", c);
	return 0;
}
