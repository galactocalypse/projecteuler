#include<stdio.h>
#include<math.h>

#define ll long long

ll gcd(ll a, ll b){
	if( a % b == 0 )return b;
	return gcd( b, a % b );
}
ll lcm(ll a, ll b){
	ll g = gcd( a, b );
	if ( a > b ) a /= g;
	else b /= g;
	return a * b;
}
int main(void){
	int i;
	ll res = 1;
	for( i = 2 ; i <= 20 ; i++ ){
		res = lcm( res, i );
	}
	printf("%d", res);
	return 0;
}
