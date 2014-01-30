/*
1
2
6
24
120
720
5040
40320
362880
3628800

0[1 - 362880]
1[362880 - ]
2[]
findPerm(set s, n){
	sz = s.size()
	if(n > sz! )return null;
	
	sort s;
	b_size = (sz-1)!
	for(i in 1..sz-1)
		if(n <= i*b_size)
			set s[i]
			remove s[i] from set
			return findPerm(s, n-(i-1)*b_size)
	return null;
}
*/
#include<stdio.h>
#define ll long long
int rp = 0;
int res[100] = {0};
ll fact(int n){
	if(n <= 1)return 1;
	return n*fact(n-1);
}
void printArr(int *arr, int sz){
             int i;
             for(i=0;i<sz;i++)
                 printf("%d, ", arr[i]);
             printf("\n");
}
void findPerm(int* arr, int size, ll n){
	ll f = fact(size);
	ll b_s;
	int i, t, j;
	if (size == 0 || n > f){
         return;
    }
	if(size == 1){
	     res[rp++] = arr[0];
	     return;
	}
	b_s = f/size;
	for( i = 0 ; i < size ; i++ ){
		if( n <= (i+1) * b_s ){
			res[rp++] = arr[i];
			if(i>0){
				/*swap*/
				t = arr[i];
				arr[i] = arr[0];
				arr[0] = t;

				/*sort*/
				t = arr[i];
				for(j = i-1; j>0; j--)
					arr[j+1] = arr[j];
				arr[1] = t;
			}
			findPerm(arr+1, size-1, n-(i*b_s));
			return;
		}
	}
}
int main(void){
	int i, t;
	ll n;
	int inp[20] = {0};
	//printf("%lld\n", fact(20));
	scanf("%d %lld", &t, &n);
	for(i=0; i < t; i++)
		inp[i] = i;
	/*assuming array to be sorted initially*/
	findPerm(inp, t, n);
	for( i = 0; i < rp; i++){
		printf("%d, ", res[i]);
	}
	getchar();
	return 0;
}
