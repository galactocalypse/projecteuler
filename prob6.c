#include<stdio.h>
#define ll long long

ll sumofsq( int n ){
	return n * ( n + 1 ) * ( 2 * n + 1) / 6;
}
ll sqofsum( int n ){
	return n * n * ( n + 1 ) * ( n + 1 )/ 4 
}
int main(void){

	printf("%lld", sqofsum( 100 ) - sumofsq( 100 ));
	
	return 0;
}