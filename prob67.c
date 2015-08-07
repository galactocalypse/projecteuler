#include<stdio.h>

#define max(a, b) ((a)>(b)? (a) : (b))
int main(void){
	int i, j, m;
	int size = 100;
	int arr[100][100] = {0};
	FILE *f = fopen("inp67.txt", "r");
	for( i = 0; i < size ; i++ ){
		for( j = 0; j <= i ; j++ ){
			fscanf( f, "%d", &arr[i][j] );
		}
	}
	fclose(f);
	/*
	int arr[4][4] = {{3},
					{7, 4},
					{2, 4, 6},
					{8, 5, 9, 3}};

	*/
	
	for( i = 1 ; i < size ; i++ ){
		for( j = 0 ; j <= i ; j++ ){
			if(j>0)
				arr[i][j] += max(arr[i-1][j], arr[i-1][j-1]);
			else arr[i][j] += arr[i-1][j];
		}
	}
	m = arr[size-1][0];
	for( i = 1 ; i < size ; i++ )
		if( arr[ size - 1 ][ i ] > m) m = arr[ size - 1 ][ i ];
	printf("%d", m);
	getchar();
	return 0;
}
