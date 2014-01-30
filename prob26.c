#include<stdio.h>
#include<math.h>
int findRecurLength(int n){
	int arr[1000] = {0};
	long long div, r;
	int i;
	int q[1000] = {0};
	int rem[1000] = {0};
	int rp=0;
	int qp=0;
	if(n == 2 || n == 5)return 0;
	if(n%2 == 0)return findRecurLength(n/2);
	if(n%5 == 0)return findRecurLength(n/5);
	
	div = 1;
	while(div < n)div*=10;
	div/=10;
	do{
		div*=10;
		q[qp++] = div/n;
		rem[rp++] = div%n;
		div = rem[rp-1];
		//printf("q: %d, r: %d\n", q[qp-1], rem[rp-1]);
		for( i = qp-2; i >=0 ; i--)
			if(q[i] == q[qp-1] && rem[i] == rem[rp-1]){
				//printf("%d\n", q[i]);
				return qp-i-1;
			}
	}while(1);
	return 0;
}
int main(void){
	int i, m = 0, x, d = 0;
	for(i=1;i<1000;i++){
		x = findRecurLength(i);
		if(x > m){m=x;d=i;}
	}
	printf("%d", d);
	return 0;
}
