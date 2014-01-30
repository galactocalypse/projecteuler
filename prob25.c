#include<stdio.h>
#include<math.h>
#define PHI 1.618033988749894848204586834
#define N 1000
int main(void){
	double x = (999 + log10(5.0)/2.0)/log10(PHI);
	printf("%lld", (long long)(x+1.0));
	return 0;
}
