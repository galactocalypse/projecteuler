/*
For once I know a formula beforehand.

Pretty straightforward. Just wish I could make this run faster.

Output:
------
8319823
16.2731s

*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>

#define rep(i, s, n) for(i = (s); i < (n); i++)
#define LIM 1000000000

using namespace std;

ostringstream op;
int primes[3163];
int pc;
void pv(vector<int> v){
	op << "[";
	for(int i = 0; i < v.size(); i++)
		op << v[i] << " ";
	op << "]" << endl;
}

void printarr(int *a, int n){
	int i;
	rep(i, 0, n)
		op << a[i]<< " ";
	op << endl;
}

void sieve(){
	bool s[3163];
	pc = 0;
	for(int i = 0; i < 3163; i++){
		s[i] = true;
	}
	for(int i = 2; i <3163; i++){
		if(s[i]){
			for(int j = i*i; j < 3163; j+= i){
				s[j] = false;
			}
			primes[pc++] = i;
		}
	}
}

bool isprime(int n){
	for(int i = 0; i < pc && primes[i]*primes[i] <= n; i++){
		if(n%primes[i] == 0)
			return false;
	}
	return true;
}

int phi(int n){
	int p = n;
	for(int i = 0; n > 1 && i < pc; i++){
		if(n%primes[i] == 0){
			p = p/primes[i]*(primes[i] - 1);
		}
		while(n%primes[i] == 0)
			n /= primes[i];
	}
	if(n > 1)
		p = p/n*(n-1);
	return p;
}

bool comp(int a, int b){
	int n[10];
	for(int i = 0; i < 10; i++)
		n[i] = 0;
	do{
		n[a%10]++;
		a/=10;
	}while(a);
	while(b){
		n[b%10]--;
		b/=10;
	}
	for(int i = 0; i < 10; i++)
		if(n[i])
			return false;
	return true;
}

int main(int argc, char** argv){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	clock_t t_start, t_end;
	t_start = clock();
	sieve();
	int mi = 0, mp;
	for(int i = 7; i < 10000000; i+=2){
		int p = phi(i);
		if(comp(i, p)){
			if(!mi || (long long)mi*p > (long long)i*mp){
				mi = i;
				mp = p;
			}
		}
	}
	cout << mi << endl;
	t_end = clock();
	op << (double)(t_end - t_start)/CLOCKS_PER_SEC << "s" << endl;
	cout << op.str();
	return 0;
}

