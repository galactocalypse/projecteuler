/*
P(n) = n(3n - 1)/2
P(i+n)-P(i) = (i+n)(3(i+n) - 1)/2 - i(3i - 1)/2
			= (i+n)(3i + 3n - 1)/2 - (3i^2 - i)/2
			= (3i^2 + (3n - 1)i - n + 3n^2 - 3i^2 + i)/2
			= (3ni - n + 3n^2 )/2
			= n(3i + 3n - 1)/2
Hence, as i increases, difference between successive terms increases.
So, we're looking for the first(smallest) (P(j), P(k)) pair.

We still don't have an upperbound, though.
This one seems to be heading the guesswork way as well.

For a given P(n) = n(3n - 1)/2 = x,
	n = (1 + sqrt(1 + 24*x))/6

No good upto 10000. Oh, wait.
I guess I set i <= j and processed it assuming i >= j.

Referring to Mathblog. Again.
Pretty sure I fucked up in the validating functions.

Duh. Broke out of one loop just the inner loop. Should develop deeper attachment with my variables.
Covered well within 10000. Dunno how to shrink the solution space, though.

*/
#include<stdio.h>
#include<math.h>
#define OFF 1
#define LIM 10000
#define P(x) (x*(3*x - 1)/2)
int isPent(int n){
	int x = 1 + 24*n;
	double s = sqrt(x);
	if(ceil(s) != floor(s))return 0;
	x = floor(s);
	return ((x + 1) % 6 == 0);
}
int check(int j, int i){
	int p = P(i), q = P(j);
	return (isPent(p + q) && isPent(p - q))?(p-q):0;
}
int main(void){
	int i, j, c = 0;
	for(i = OFF; i < LIM; i++)
		if(c)break;
		else 
		for( j = OFF; j<= LIM; j++)
			if(c = check(i, j))
			break;
	
	printf("%d", c);
	return 0;
}
