#include<stdio.h>
int isValid(int i, int j, int k){
	int x = 0;
	int arr[10] = {0};
	do{arr[i%10]++;}while(i/=10);
	do{arr[j%10]++;}while(j/=10);
	do{arr[k%10]++;}while(k/=10);
	if(arr[0])return 0;
	for(x=1;x<10;x++)
		if(arr[x]!=1)return 0;
	return 1;
}
int main(void){
	/*
	1 4 4
	2 3 4
	3 3 3
	*/
	int arr[200]={0};
	int ap = 0;
	int i, j;
	long long sum = 0;
	for(i = 1; i<= 9; i++){
		for( j = 12; j<= 9876/i ; j++){
			if(isValid(i, j, i*j)){
				arr[ap++] = i*j;
				//printf("%d * %d = %d\n", i, j, i*j);
			}
		}
	}
	for(i = 11; i<= 98; i++){
		for( j = 123; j<= 9876/i ; j++){
			if(isValid(i, j, i*j)){
				arr[ap++] = i*j;
				//printf("%d * %d = %d\n", i, j, i*j);
			}
		}
	}
	for(i = 123; i<= 987; i++){
		for( j = 123; j<= 9876/i ; j++){
			if(isValid(i, j, i*j)){
				arr[ap++] = i*j;
				//printf("%d * %d = %d\n", i, j, i*j);
			}
		}
	}
	for(i = 1; i < ap ; i++)
		for( j = 0; j < i ; j++)
			if(arr[i] == arr[j])arr[j] = 0;
	for(i=0;i<ap;i++)
		sum+=arr[i];
	printf("%lld", sum);
	return 0;
}