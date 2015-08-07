#include<stdio.h>
int main(void){
	long long arr[202][8]={0};
	int i, j;
	int coins[8] = {1,2,5,10,20,50,100,200};
	for(i=0;i<=201;i++)arr[i][0] = 1;
	for(i=1;i<=201;i++){
		for(j=1;j<8;j++){
			arr[i][j] = arr[i][j-1];
			if(i >= coins[j])arr[i][j] += arr[i-coins[j]][j];
		}
	}
	printf("%d\n", arr[201][7]);
	return 0;
}
