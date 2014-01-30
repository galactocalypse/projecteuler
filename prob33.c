#include<stdio.h>
int isCur(int i, int j){
	int a = i%10, b = i/10, c = j%10, d = j/10;
/*
	a=c
	a=d
	b=c
	b=d
*/
	if(a == c && a>0 )
		if(i*d == j*b)return 1;
	if(a == d)
		if(i*c == j*b)return 1;
	if(b == c)
		if(i*d == j*a)return 1;
	if(b == d)
		if(i*c == j*a)return 1;
	return 0;
}
int gcd(int a, int b){
	if(a%b==0)return b;
	return gcd(b, a%b);
}
int main(void){
	int i, j, num = 1, deno = 1, g;
	for(i = 10; i <= 99 ; i++){
		for(j = 10; j < i; j++){
			if(isCur(i, j)){
				//printf("%d/%d\n", j, i);
				num *= j;
				deno *= i;
			}
		}
	}
	while((g = gcd(num, deno)) != 1){
		num/=g;
		deno/=g;
	}
	printf("%d", deno);
	return 0;
}
