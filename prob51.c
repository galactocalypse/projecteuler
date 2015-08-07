/*
I like how the problems get mathematical without getting too heavy on the head.

This is trickier than it looks.
For an N digit number:
	if 1 digit is changed		N possibilities
	if 2 digits are changed		NC2 possibilities
	if 3 digit are changed		NC3 possibilities
	...
	Alright, this is not the way to go.

The only thing I think can reduce the problem size is the fact that we need the smallest "prime."
Again, blindly assuming that our answer is smaller than 2 million, we use the same set of primes we have been using so far.
150000 numbers.
For an N (<= 7) digit number:
for 1 digit :	combinations of spots to change = N
for 2 digits:	combinations of spots to change = NC2
for 3 digits:	combinations of spots to change = NC2

Total combinations = NC1 + NC2 + NC3 + ... + NC(N-1)
= 2^N - NC0 - NCN = 2^N - 2 ~ 2^N
= 2^7 (max) = 128
Number of replacements for each number = 10
(edit: ^jaali calculation. This won't work.)
Mathblog has some serious insight. I misunderstood this question as well.

This is probably the most challenging problem so far.
Wouldn't have had any idea about it had it not been for Mathblog and SO.
I guess I won't refer to them next problem onward. Should build some insight.


I finally understood what Mb and SO had to say; could've stated it in a simpler manner.
All the've considered is that the number's divisibility with 3 should be considered while replacing the digits since for some cases, it wouldn't be possible to have a family of eight prime members.

Alright, starting from scratch:
1. We need to find a prime with some repeated digits(including 0 repetitions) such that replacing those repeated digits with some other digit can lead to seven more primes.
2. Given that seven more primes are required and we need the smallest member of the family, the repeated digit must be in [0, 9-7].
3. Let the number have x repeated digits d and the sum of the remaining numbers be s.
So, since n is prime, (s + xd)%3 != 0
	or, (s%3 + xd%3) = 1 or 2
	We wish to replace d with d' while maintaining that (s + xd')%3 != 0
	Let s%3 = t
	We will now consider what values of d' are possible for various values of x:
	For x = 1:
		(t + d')%3 != 0
		for t = 0, d' = {1, 2, 4, 5, 7, 8}
		for t = 1, d' = {0, 1, 3, 4, 6, 7, 9}
		for t = 2, d' = {0, 2, 3, 5, 6, 8, 9}
	Hence, if x = 1, there is no way we can get a family of eight primes.
	For x = 2:
		(t + 2*d')%3 != 0
		for t = 0, d' = {1, 2, 4, 5, 7, 8}
		for t = 1, d' = {0, 2, 3, 5, 6, 8, 9}
		for t = 2, d' = {0, 1, 3, 4, 6, 7, 9}
	Hence, if x = 2, there is no way we can get a family of eight primes.
	For x = 3:
		(t + 3*d')%3 != 0
		Since 3*d' % 3 = 0, t%3 != 0
		for t = 0, d' = {}
		for t = 1, d' = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
		for t = 2, d' = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	Hence, if x = 3, we can get a family of eight or more members if t % 3 != 0.

We now know what we're looking for.
We can now try searching for the solution in small numbers(~10^5 - 10~6).
In case we don't find an answer, we'll have to develop a deeper insight, but Mathblog says the answer can be found in this range(they assume as well).

To generate all five digit numbers with three repeated digits, we follow Mathblog's procedure and generate all 2-digit numbers.
We then introduce the same digit in that number in three places in all ways possible.

For a 2-digit number 10x+y, three digits can be included in the following manners. (We must keep in mind that the order of x and y should not be changed.):
	xy___
	x_y__
	x__y_
>	x___y
	_xy__
	_x_y_
>	_x__y
	__xy_
>	__x_y
>	___xy
We can verify that there would be at the most 10 possibilities, since 5C2 = 5!/2!3! = 120/(2*6) = 10
We can follow the same approach for 6 digit numbers, but we'll try that only if we don't find a 5-digit answer.

We can further reduce the number of combinations we need to try by observing that we can't have the repeated digits at the end of the number, since (as Mathblog mentions) all primes > 10 end in 1, 3, 7 or 9 and having only four permissible values won't suffice in finding a family of the requisite eight members.
That reduces four combinations per number.
We can further reduce the number of combinations by realizing that the last digit will remain unchanged, so it must not be an even number.

Eh. Didn't work for five digits. That Mathblog code runs ten times faster than mine. :/
Using arrays for number generation is probably overkill, but I'd keep optimization aside while we don't find an answer.
For three digit numbers, we'll have more trouble generating the numbers.
Possible combinations: 6C3 = 6!/3!.3! = 720 / 36 = 20

Oh, shit. Wrote the code for the 5-digit thing wrong.
Won't correct it, since that doesn't fetch the answer anyway.
Alright, corrected it.

No answer for the six-digit version either.
Okay, program was almost fine, just forgot to intialize the array(placing the fixed digits).

Phew. Most difficult problem attempted so far.
*/
#include<stdio.h>
#include<math.h>

#define MAX 1000000
int primes[500000];
int np;

void populate()
{
    int d, i, j, lim, isp;
    np = 0;
    d = 4;
    primes[np++] = 2;
    primes[np++] = 3;
    primes[np++] = 5;
    primes[np++] = 7;
    for (i = 11; i < MAX; i += d) {

	lim = (int) ceil(sqrt(i));
	isp = 1;
	for (j = 0; primes[j] <= lim; j++) {
	    if (i % primes[j] == 0) {
		isp = 0;
		break;
	    }
	}
	if (isp)
	    primes[np++] = i;
	d = 6 - d;
    }

}
int isSq(int x){
	double s = sqrt(x);
	return (ceil(s) == floor(s));
}
int binsearch(int *arr, int l, int r, int s){
	int m = (l+r)/2;
	if(arr[m] == s)return m;
	if(l >= r)return -1;
	if(s < arr[m])return binsearch(arr, l, m, s);
	return binsearch(arr, m+1, r, s);
}
int isPrime(int n){
	return binsearch(primes, 0, np-1, n) != -1;
}
int checkNum(int n){
	int a, b, c, ctr, sm, t = n;
	int i, j, k, d;
	int arr[10] = {0};
	a = n/100;
	b = (n/10)%10;
	c = n%10;
	for(i = 0; i < 3; i++){
		for(j = i+1; j < 4; j++){
			arr[5] = c;
			arr[i] = a;
			arr[j] = b;
			ctr = 0;
			for(d = 0; d <= 9; d++){
				for( k = 0; k < 5; k++)
					if(k != i && k != j)arr[k] = d;
				n = 0;
				for(k=0; k < 6; k++)
					n = n*10 + arr[k];
				if(isPrime(n))ctr++;
				if(ctr == 1){
					sm = n;
					//printf("SP : %d for %d\n", sm, t);
				}
				if(ctr == 8 || ctr + 9 - d < 8)break;
			}
			if(ctr == 8){
				return sm;
			}
		}
	}
	return 0;
}
int main(void){
    int i, sum = 0, c = 0, f, j;
	populate();
	for(i = 101; i < 1000; i+=2)
		if(c = checkNum(i))break;
	printf("%d", c);
	return 0;
}
