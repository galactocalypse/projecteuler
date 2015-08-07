/*
I am assuming this one is straightforward.

If nCr is >= 10^6 for some r <= n/2, it must be > 10^6 for all r thereafter, upto (n - r).
All we need to find is the lowest r for which nCr >= 1000000.

As zobayer suggests, from Pascal's triangular relation we get:
nCr = n-1Cr + n-1Cr-1

We know that:
	nC0 = 1 for all n
	nC1 = n for all n
	and n >= r
This is sufficient to start forming a dp solution.
Incorrect answer! Ignored boundaries.

1
1 1
1 2 1
1 3 3  1
1 4 6  4  1
1 5 10 10 5  1
1 6 15 20 15 6  1
1 7 21 35 35 21 7 1

If (i, j) is the first occrrence of of number >= 10^6, the first occurrences in the (i+1)th and subsequent rows will be < j.

Correct answer!
*/
#include<stdio.h>
int main(void){
	int dp[101][101] = {0};
	int sum = 0, i, j;
	dp[0][0] = 1;
	for(i = 1; i < 101; i++){
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	for( i = 1; i < 101; i++){
		for( j = 1; j <= i ; j++){
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			if(dp[i][j] >= 1000000){
				//printf("%d %d\n", i, j);
				sum += (i - 2*j +1);
				break;
			}
			
		}
	}
	printf("%d", sum);
	return 0;
}
