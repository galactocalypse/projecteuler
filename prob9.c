#include<stdio.h>
#include<math.h>
#include<string.h>
int main(void){
	int a, b, c, res = 0;
	for( a = 1; a < 500; a++ ){
		for( b = a + 1 ; b < 500 ; b++ ){
			c = 1000 - a - b;
			if( a*a + b*b == c*c ){
				res = a*b*c;
				break;
			}
		}
		if(res)break;
	}
	printf("%d", res);
	return 0;
}