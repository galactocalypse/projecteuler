#include<stdio.h>
#include<math.h>

int get_digits(int n){
	double x = 0.0;
	int i;
	for(i=1; i<= n; i++)
		x += log10(i);
	return ceil(x);
}
int main(void){
	int i, n = 100;
	/* int d = get_digits(n); -> returns 158 */
	int d = 158;
	int c, j;
	int arr[158] = {0};
	arr[0] = 1;
	for( i = 2; i <= n; i++ ){
		c = 0;
		for ( j = 0; j < d ; j++ ){
			arr[j] = (c + arr[j]*i);
			c = arr[j]/10;
			arr[j] %= 10;
		}
	}
	c = 0;
	for( i = 0; i < d; i++ )
		c += arr[i];

	printf("%d", c);
	return 0;
}
