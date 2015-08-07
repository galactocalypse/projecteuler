#include<stdio.h>
#include<math.h>
int sod(int n){
	int s = 0;
	while(n){
		s+=(int)pow(n%10, 5);
		n/=10;
	}
	return s;
}
int main(void){
	int i;
	int s = 0;
    for( i = 10; i<=355000; i++){
    	if(sod(i) == i)s+=i;
    }
    printf("%d\n", s);
	return 0;
}
