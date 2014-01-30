/*
This is going to be a dirty solution.
Can't tell the maths behind this.
*/
#include<stdio.h>
#include<math.h>

#define MAX 2000000
int primes[500000];
int np;

void populate()
{
    int d, i, j, lim, isp;
    np = 0;
    d = 4;
    primes[np++] = 2;
    primes[np++] = 3;
    primes[np++] = 5;
    primes[np++] = 7;
    for (i = 11; i < MAX; i += d) {

	lim = (int) ceil(sqrt(i));
	isp = 1;
	for (j = 0; primes[j] <= lim; j++) {
	    if (i % primes[j] == 0) {
		isp = 0;
		break;
	    }
	}
	if (isp)
	    primes[np++] = i;
	d = 6 - d;
    }

}
int cmpdigs(int a, int b){
	int arr[10] = {0};
	int i;
	while(a){
		arr[a%10]++;
		a/=10;
	}
	while(b){
		arr[b%10]--;
		b/=10;
	}
	for(i=0;i<10;i++)
		if(arr[i]!=0)return 0;
	return 1;
}
int main(void){
    int i, sum = 0, c = 0, f, j, t, ans, div, x, y, z;
	populate();
	//printf("%d", cmpdigs(1012,2011));
	//return 0;
	for(i = 0; primes[i] < 1000; i++);
	j = t = i;
	for( ; primes[i] <= 9999; i++){
		x = i;
		y = z = 0;

		for(j = i + 1 ; primes[j] <= 9999; j++){
			if(cmpdigs(primes[i], primes[j])){
				if(y){
					z = j;
					break;
				}
				else y = j;
			}
		}
		if(z){
			if(primes[z] - primes[y] == primes[y] - primes[x])
			break;
		}
	}
	printf("%d%d%d", primes[x], primes[y], primes[z]);
	return 0;
}
