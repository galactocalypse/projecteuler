/*
Again, couldn't do much math.
All I figured was that 3a <= 1000 and c < 500(hence b < 500).
*/
#include<stdio.h>
#include<math.h>
#define max(a, b) ((a)>(b)?(a):(b))
int arr[1001];
int main(void){
	int a, b, c, i, m;
	for( a = 1; a <= 333; a++ ){
		for( b = a; b < 500; b++ ){
			if(floor(sqrt(a*a + b*b)) == ceil(sqrt(a*a + b*b))){
				c = floor(sqrt(a*a + b*b));
				if(a+b+c <= 1000)arr[a+b+c]++;
			}
		}
	}
	m = 0;
	for(i = 4; i<= 1000 ; i++)
		if(arr[i] > arr[m])m = i;
	printf("%d", m);
	return 0;
}
