/*
N^2 after memoization.
This should have a better solution.

This code will fail if 2 is included in the final answer.
I am assuming it isn't, so I won't need to add an extra condition for accessing arr[-1].

Changed that bit of code, wrote a separate routine instead of computing the difference directly.

Interesting problem, this. I sieved the primes upto 2 million(copied code from some previous problem), which comes to roughly 150000 numbers.
Since we had to compute the sums between every combination of start and end points, the algorithm went upto N^2, which was roughly 10^10 in this case.
So I brought the primes down to some 78000 by setting the limit to 1000000(which was all we needed for this problem). Surprisingly, even that fetched a TLE.

Minor addition to break from the inner loop if the current sum got beyond 1000000 got the thing working pretty fast. Yet to check the answer, though.

*/
#include<stdio.h>
#include<math.h>

#define MAX 1000000
int primes[500000];
int np;
int arr[150000];
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

}int binsearch(int *arr, int l, int r, int s){
	int m = (l+r)/2;
	if(arr[m] == s)return m;
	if(l >= r)return -1;
	if(s < arr[m])return binsearch(arr, l, m, s);
	return binsearch(arr, m+1, r, s);
}
int isPrime(int n){
	return binsearch(primes, 0, np-1, n) != -1;
}
int getSum(int i, int j){//[i, j])
	i--;
	if( i <= -1)return arr[j];
	return arr[j] - arr[i];
}
int main(void){
    int i, sum = 0, c = 0, f, j, t, ans, div, x, y, z, m = 0;
	populate();
	arr[0] = primes[0];
	for(i = 1; i < np; i++)
		arr[i] = arr[i-1] + primes[i];
	//printf("%d", np);
	//return 0;
	for(i = 0; i < np - 1; i++){
		for(j = i; j <= np; j++){
			if(getSum(i, j) >= 1000000 )break;
			if(isPrime(getSum(i, j))){
				if(j - i + 1 > m){
					m = j - i;
					ans = getSum(i, j);
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
