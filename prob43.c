/*
Will finally have to get my hands dirty with array-based generation.

*/
#include<stdio.h>
int arr[10] = {1,4,0,6,3,5,7,2,8,9};
int bs[11] = {0};
int add(){
	int i, c = 0;
	for( i = 9; i>=0; i--){
		c = c+arr[i]+bs[i+1];
		bs[i+1] = c%10;
		c = c/10;
	}
	bs[0] = bs[0] + c;
}
int inc(){
	int i, j;
	int c[10] = {0};
	c[arr[9]]++;
	for(i = 8; i>= 0; i--){
		c[arr[i]]++;
		if(arr[i + 1] > arr[i]){
			for( j = arr[i] + 1; j <= 9; j++ )
				if(c[j])break;
			arr[i] = j;
			c[j] = 0;
			for( j=0 ; j <= 9; j++ )
				if(c[j])arr[++i] = j;
			return 1;
		}
	}
	return 0;
}
int printNum(){
	int i;
	for(i = 0; i < 10; i++)
		printf("%d", arr[i]);
	printf("\n");
}
int check(){
	int i, num;
	int p[7] = {2,3,5,7,11,13,17};
	for( i = 1; i <= 7; i++ ){
		num = 100*arr[i] + 10*arr[i+1] + arr[i+2];
		//printf("%d mod %d\n", num, p[i-1]);
		if(num % p[i-1])return 0;
	}
	return 1;
}
int main(void){
	int i = 0;
	do{
		if(check()){
			i++;
			add();
		}
	}while(inc());
	for(i=0;i<11;i++)
		printf("%d", bs[i]);
	return 0;
}
