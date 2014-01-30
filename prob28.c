#include<stdio.h>
int main(void){
	int i;
	long long sum = 1;
	for( i = 1; i <= 500 ; i++ )
		sum += ( 4 + 4*i +16*i*i );
	printf("%lld", sum);
	return 0;
}
