/*
2dig 2<= sum <= 99
3dig 3<= sum <= 999
3dig 4<= sum <= 9999
5dig 5<= sum <= 99999
6dig 6<= sum <= 999999
7dig 7<= sum <= 9999999


     99 <= 725760
    999 <= 1088640
   9999 <= 1451520
  99999 <= 1814400
 999999 <= 2177280
9999999 <= 2540160

check only upto seven digits since after that 9!*x < 10^x-1 */

#include<stdio.h>
#include<math.h>
long long f[10] = {1,1,2,6,24,120,720,5040,40320,362880};
long long factsum(int n){
	long long sum = 0;
	while(n){
		sum+=f[n%10];
		n/=10;
	}
	return sum;
}
int main(void){
	long long i, j, s, m, sum = 0;
	for(i=2; i<= 7; i++){
		m = pow(10, i) - 1;
		for(j=(int)pow(10, i-1); j<= m; j++){
			s = factsum(j);
			if(s == j){
				sum+=s;
				//printf("%lld\n", s);
			}
		}
	}
	printf("%lld", sum);
	return 0;
}
