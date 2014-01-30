#include<stdio.h>
int main(void){
	int i;
	double p = 1, q = 1;
	for( i = 1; i <= 20 ; i++ ){
		p *= (double)i;
		q *= (20.0 + i);
		printf("%lf, %lf\n", p, q);
	}
	printf("%lf", q/(double)p);
	return 0;
}