/*
	This program definitely needs time-monitoring.
	
	We have reached a stage where we can see a number of four-member sets that are eligible. Can't find any 55-member sets yet.
	
	We finally find 3 eligible sets. Theoretically, we should keep checking primes till the smallest candidate element exceeds one-fifth of the existing sum. But we surely have better uses for our computing power.

	Probably the most tiring problem (both for myself and my computer) so far. And one of my longest C codes.
	
	Might want to get it to work faster. 2.39 seconds to find the minimal sum as of now.

	Just in case it is required again, I'm retaining the file out60 which contains all pairs. Generating them takes about 67 seconds. Might not want to wait that long every time.
	
	Results:
	Generated sieve of 3246 primes in 0.000s
	Generated 93204 pairs in 68.890s
	7 1237 2341 12409 18433
	13 5197 5701 6733 8389
	467 941 2099 19793 25253
	Minimal sum: 26033 calculated in 2.380s

	Note:
	For some weird reason, no solution is found when the pairs are generated directly. If they are written to and read from a file, instead, everything works fine. Need to fix that.

*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define rep(i, s, n) for(i = (s); i < (n); i++)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define LIM 30001
#define PLIM 100001

int cmp(const void *, const void *);
int sod(int);
void genpairs();
int nod(int);
int checkpair(int, int);
void sieve();
int search(int);
int binsearch(int, int, int);
int isp(long long);
void printarr(int *, int);
int findlowest(int, int, int);
int ispair(int, int);
void findgroups();

typedef struct pair{
	int a;
	int b;
} pair;

char *pairfile = "out60";
int g[5] = {0};
int p[LIM] = {0};
int primes = 0;
pair pp[PLIM] = {0};
long long pairs = 0;
int sum = 0;

int sod(int n){
	int s = 0;
	while(n){
		s += n%10;
		n /= 10;
	}
	return s;
}

int nod(int n){
	return 1 + log10(n);
}

int checkpair(int a, int b){
	long long m, n;
	/*assuming a and b to be prime*/
	m = a*pow(10, nod(b))+b;
	n = b*pow(10, nod(a))+a;
	//printf("Checking %lld and %lld: %d %d\n", m, n, isp(m), isp(n));
	return (isp(m) && isp(n));
}

void genpairs(){
	int i, j;
	pairs = 0;
	rep(i, 0, primes){
		rep(j, i+1, primes){
			if((sod(p[i])+sod(p[j]))%3 == 0)// prelim checks just to hurry things up
				continue;
			if(checkpair(p[i], p[j]) == 1){
				pp[pairs].a = i;
				pp[pairs].a = j;
				pairs++;
				if(pairs == PLIM){
					return;
				}
			}
		}
	}
}

void sieve(){
	int i;
	int j;
	int l = sqrt(LIM);
	int a[LIM];
	rep(i, 2, LIM)
		a[i] = 1;

	for(i = 2; i < l; i++){
		if(a[i])
			for(j = i*i; j < LIM; j += i)
				a[j] = 0;
	}
	primes = 0;
	rep(i, 2, LIM){
		if(a[i])
			p[primes++] = i;
	}
}

int search(int s){
	return binsearch(0, primes-1, s);
}

int binsearch(int l, int h, int s){
	int m = (l+h)/2;
	//printf("BS called with: %d %d %d\n", l, h, s);
	if(l > h)return -1;
	if(p[m] == s)return m;
	if(s > p[m])return binsearch(m+1, h, s);
	return binsearch(l, m-1, s);
}

int isp(long long n){
	int l = sqrt(n), i;
	if(n < LIM)
		return !(search(n) == -1);
	for(i = 0; i < primes; i++){
		if(p[i] > l)break;
		if(n % p[i] == 0)return 0;
	}
	return 1;
}

void printarr(int *arr, int n){
	int i;
	rep(i, 0, n){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int findlowest(int l, int h, int s){
	//find lowest index such that pp[i].a == s
	int mid = (l+h)/2;
	if(l > h)return -1;
	if(s == pp[l].a)return l;
	if(s > pp[mid].a)return findlowest(mid+1, h, s);
	if(s < pp[mid].a)return findlowest(l, mid-1, s);
	if(s == pp[mid].a)return findlowest(l, mid, s);
	return -1;
}

int ispair(int a, int b){
	/* a and b are indices */
	int s, e;
	int ans = 0;

	if(b < a)ans = ispair(b, a);
	else {
		s = findlowest(0, pairs - 1, a);
		//printf("Lowest of ind %d is: %d\n", a, s);
		if(s == -1)
			ans = 0;
		else{
			while(s < pairs && pp[s].a == a && pp[s].b <= b)
				if(pp[s++].b == b){
					ans = 1;
					break;
				}
		}
	}
	//printf("Checking pair: %d %d (%d, %d): %d\n", a, b, p[a], p[b], ans);
	return ans;
}

void checkfrom(int a){// generate solution starting with index i

	int ind = findlowest(0, pairs-1, a);
	int i, j, k, l;
	for(i = ind; i < pairs && pp[i].a == a; i++){
		for(j = i+1; j < pairs && pp[j].a == a ; j++){
			if(!ispair(pp[i].b, pp[j].b))
				continue;
			for(k = j+1; k < pairs && pp[k].a == a; k++){
				if(!ispair(pp[i].b, pp[k].b) || !ispair(pp[j].b, pp[k].b))
					continue;
				for(l = k+1; l < pairs && pp[l].a == a; l++){
					if(!ispair(pp[i].b, pp[l].b) || !ispair(pp[j].b, pp[l].b) || !ispair(pp[k].b, pp[l].b))
						continue;
					printf("%d %d %d %d %d\n", p[a], p[pp[i].b], p[pp[j].b], p[pp[k].b], p[pp[l].b]);
					if(sum)
						sum = min(sum, p[a] + p[pp[i].b] + p[pp[j].b] + p[pp[k].b] + p[pp[l].b]);
					else sum = p[a] + p[pp[i].b] + p[pp[j].b] + p[pp[k].b] + p[pp[l].b];
				}
			}
		}
	}
}

void findgroups(){
	int i;
	sum = 0;
	for(i = 0; i < primes; i++){
		if(sum && sum < 5*p[i])break;
		checkfrom(i);
	}
}

int writepairstofile(char *fn){
	FILE *fp;
	int i;
	if(fp == NULL || !pairs)return 0;
	fp = fopen(fn, "w");
	rep(i, 0, pairs)
		fprintf(fp, "%d %d\n", pp[i].a, pp[i].b);
	fclose(fp);
	return 1;
}

int readpairsfromfile(char *fn){
	FILE *fp;
	int i = 0;
	fp = fopen(fn, "r");
	if(fp == NULL)return 0;
	pairs = 0;
	while(fscanf(fp, "%d %d", &pp[i].a, &pp[i].b) == 2)
		i++;
	pairs = i;
	if(!pairs)return 0;
	fclose(fp);	
	return 1;
}

int main(int argc, char **argv){
	FILE *fp;
	int a, b, i, x, j, c, d, e;
	double t;
	clock_t ss, ee;
	
	ss = clock();
	sieve();
	ee = clock();
	printf("Generated sieve of %d primes in %.3lfs\n", primes, (double)(ee-ss)/CLOCKS_PER_SEC);
	
	ss = clock();
	if(!readpairsfromfile(pairfile)){
		genpairs();
		writepairstofile(pairfile);
		if(!readpairsfromfile(pairfile)){
			printf("Cannot write to file %s. Terminating program.\n", pairfile);
			return 0;
		}
		
	}
	
	ee = clock();
	printf("Generated %lld pairs in %.3lfs\n", pairs, (double)(ee - ss)/CLOCKS_PER_SEC);
	
	ss = clock();
	findgroups();
	ee = clock();
	printf("Minimal sum: %d calculated in %.3lfs\n", sum, (double)(ee-ss)/CLOCKS_PER_SEC);
	return 0;
}

