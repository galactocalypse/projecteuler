#include<stdio.h>
#include<math.h>

#define MAX 600851475143
#define ROOT 775146
#define ll long long

int main(void){
	int arr[1000000] = {0};
	int i = 2;
	int c = 0;
	ll j;
	int lastprime = -1;
	arr[0] = 1;
	arr[1] = 1;
	
	for( ; i <= ROOT ; i++ ){
		if(!arr[i]){
			for( j = ((ll)i*i); j <= ROOT ; j += i )
				arr[j] = 1;
			lastprime = i;
		}
	}
	for( i = 2 ; i < ROOT ; i++ ){
		if( !arr[i] ) c++;
		if( c == 10001 )break;
	}
	printf("%d", i);
	return 0;
}
