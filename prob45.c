/*
Again, no idea of how to set an upper bound.
I'm planning to store, iterate and binary search. Let's see how far that works.

I don't know what's happening. Things seem in place since 40755 is being detected.
Have checked upto 10^7 without an answer.

Thinking of inverting the functions and trying again.
Nah, isn't heling. Mathblog. :'(

Alright, Maths relies heavily on observation. I didn't observe that all hexagonal numbers are triangular numbers.
My solution should have worked anyway. Made a bigger mistake - forgot to account for overflows. I can't count the number of ways one can ignore overflows.

Worked! Never thought an overflow could manifest itself this way.
Amazing.
*/
#include<stdio.h>
#define OFF 286
#define LIM 10000000
long long tri[LIM+1];
long long pent[LIM+1];
long long hex[LIM+1];

int binsearch(long long *arr, int l, int r, long long s){
	int m = (l+r)/2;
	if(arr[m] == s)return m;
	if(l >= r)return -1;
	if(s < arr[m])return binsearch(arr, l, m, s);
	return binsearch(arr, m+1, r, s);
}
int gen(){
	long long i;
	for(i = OFF; i <= LIM; i++){
		tri[i] = i*(i+1)/2;
		pent[i] = i*(3*i - 1)/2;
		hex[i] = i*(2*i - 1);
	}
}
int main(void){
	int i;
	gen();
	for(i = OFF ; i <= LIM; i++)
		if(binsearch(pent, 0, LIM, tri[i]) != -1 && binsearch(hex, 0, LIM, tri[i]) != -1)break;
	printf("%lld", tri[i]);
	return 0;
}
