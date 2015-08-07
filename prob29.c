#include<stdio.h>
#include<math.h>
#include<time.h>
int main(void){
	int arr[11][601] = {0};
	int done[101] = {0};
	int i, j, x, sum = 0;
	clock_t begin, end;
	double time_spent;

	begin = clock();
	for( i = 2; i <= 10; i++ ){
		if(done[i])continue;
		x = 1;
		while(pow(i, x) <= 100){
			done[(int)pow(i, x)] = 1;
			for(j=2;j<=100;j++){
				if(arr[i][j*x])sum++;
					else arr[i][j*x] = 1;
			}
			x++;
		}
	}
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%d\n", 99*99 - sum);
	printf("%lf\n", time_spent);
	return 0;
}
