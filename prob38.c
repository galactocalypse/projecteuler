/*
Worked out manually again.
Don't know the Maths of it.
Tried with 2, 3, 4 digits.
Could only infer that things won't go beyond 4 digits.
Pathetic.
*/
#include<stdio.h>
#include<math.h>
#define max(a, b) ((a)>(b)?(a):(b))
int isPan(int *s, int n){
	int arr[10] = {0};
	int i, t;
	for(i = 1; i <= n; i++){
		t = s[i];
		while(t){
			arr[ t % 10 ]++;
			t/=10;
		}
	}
	for( i = 1 ; i < 10 ; i++ )
		if(arr[i] != 1)
			return 0;
	return 1;
}
int nod(int n){
	int  i = 0;
	while(n){
		i++;
		n /= 10;
	}
	return i;
}
int checkNum(int n){
	int d = 0, i;
	int arr[10] = {0};
	for( i = 1; i <= 9; i++){
		arr[i] = i*n;
		d+=nod(arr[i]);
		if(d>9)return 0;
		if(d==9)return isPan(arr, i)?i:0;
	}
	return 0;
}
int getVal(int n, int i){
	int sum = 0;
	int k;
	for(k = 1; k <= i; k++){
		sum = sum*pow(10, nod(n*(k))) + n*k;
	}
	return sum;
}
int main(void){
	int i, j, x, m = 0, k, l;
	for(i = 1; i <= 9; i++)
		for( j = 1; j <= 9; j++)
			if(j != i)
				for( k = 1; k <= 9; k++)
					if(k!=i && k!= j )
						for( l = 1; l <= 9; l++)
							if(l !=i && l!=j && l != k){
								x = checkNum(1000*i + 100*j + 10*k + l); 
								if(x){
									printf("Hello! %d\n", 1000*i + 100*j + 10*k + l);
									m = max(m, getVal(1000*i + 100*j + 10*k + l, x));
								}
							}
			
	printf("%d\n", m);
	return 0;
}
