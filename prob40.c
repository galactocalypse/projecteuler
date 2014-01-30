/*
This is straightforward if a lot of aux space is used.
We definitely need to avoid it.
for d = 1, 9 numbers exist
for d = 2, 99 - 9 = 90 numbers exist
for d = 3, 999 - 99 = 900 numbers exist
So, for d = n, 9*10^(n-1) numbers exist

Upto d = 1, 9 digits
Upto d = 2, 9 + 2*90 = 189 digits
Upto d = 3, 9 + 2*90 + 3*900 = 2889 digits and so on.

for index 1 < i <= 9:
	The (1 - (i-0)%1)th of (0 + ceil((i - 0 )/1))
	//getDig(1, 1)
for index 9 < i <= 189:
	The (2 - (i-9)%2)th of (9 + ceil((i - 9 )/2]))
	
	//getDig(10, 1)
	//getDig(55, 1)
for index 189 < i <= 2889:
	The (3 - (i - 189)%3)th of (99 + ceil((i - 189 )/3))
and so on.
	//getDig(370, 2)

This should be neat.

...and we get a wrong answer first up.

Bruteforcing in Java. Brb. :/
Alright, couldn't figure it out all night.
Now that I tried manually working each of the powers out, I realized I had been ignoring the fact that multiple powers of 10 can be found within the same range of i, like both 10 and 100 occur in (9, 189]. Darn.

Finally fixed this. Had to introduce a condition for %1, apart from that the formula is perfectly general.

*/

#include<stdio.h>
#include<math.h>
int getDig(int n, int d){
	int i;
	for(i = 0; i < d-1; i++)
		n/=10;
	return n%10;
}
int main(void){
	int i, x = 1, off = 0, sum = 1, dd, p = 1, nv;
	for( i = 1; x <= 1000000; i++, p *= 10){
		nv = off + 9*i*p;
		while(x <= nv  && x <= 1000000){
			//printf("%d : ", x);
			//printf(" ( %d", p - 1 + (int)ceil((x - off)/(double)i));
			//printf(", %d )\n", (int)ceil((x - off)/(double)i));
			dd = getDig( p-1 + (int)ceil((x - off)/(double)i) , i + 1 - (i==1?(x-off):(x - off)%i));
			sum *= dd;
			//printf("%d: %d\n", x, dd);
			x *= 10;
		}
		off = nv;
		//printf("off : %d\n", off);
	}
	printf("%d", sum);
	return 0;
}
