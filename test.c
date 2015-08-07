#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define rep(i, s, n) for(i = (s); i < (n); i++)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
int pp[15] = {0,0,1,1,1,1,1,2,4,4,5,5,5,6,7};

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}
int findlowest(int l, int h, int s){
	//find lowest index such that pp[i].a == s
	int mid = (l+h)/2;
	if(l > h)return -1;
	if(s == pp[l])return l;
	if(s > pp[mid])return findlowest(mid+1, h, s);
	if(s <= pp[mid])return findlowest(l, mid, s);
}

int findhighest(int l, int h, int s){
	//find highest index such that pp[i].a == s
	int mid = (l+h)/2;
	if(l > h)return -1;
	if(s == pp[h])return h;
	if(s == pp[mid])return findhighest(mid, h-1, s);
	if(s > pp[mid])return findhighest(mid+1, h, s);
	if(s < pp[mid])return findhighest(l, mid-1, s);
}


void printarr(int *arr, int n){
	int i;
	rep(i, 0, n){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(int argc, char **argv){
	int n;
	scanf("%d", &n);
	printf("%d\n", findhighest(0, 14, n));
	return 0;
}

