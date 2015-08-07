/*
	Getting back to this after ages. Sorry about that. Just a lean patch of sorts.
	Bruteforcing didn't help. The MathBlog article, which didn't make any sense earlier, finally did after I read their analysis of Problem 9.
	Here's my explanation (please pardon any inconsistencies):
		The generation of primitive Pythagorean triplets (triplets with GCD = 1) can be done as follows:
			For every coprime m and n(m > n, exactly one of m and n must be even), the following primitive triplet exists:
				m**2 + n**2, 2*m*n, m*m - n**2
		Regarding the limits upto which we need to iterate:
			p = (m**2 + n**2) + (2*m*n)  + (m*m - n**2) <= 1500000
			Or, 2*m**2 + 2*m*n < 1500000
			Or, m**2 + m*n < 1500000/2
			Since, m > n,
				m**2 < 1500000/2
		Hence, we need only check for m upto sqrt(1500000/2).
	For every primitive triplet with sum p, there would be non-primitive triplets with sums p*2, p*3 and so on, depending on their GCD. We need to count all the non-primitive triplets that exist for every primitive triplet.

	And finally, 
	
	161667
	46ms

*/
#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;
int s = 1500000;
int arr[1500001] = {};

int gcd(int a, int b){
	if(!a || !b)
		return a+b;
	return gcd(b, a%b);
}

int main(){
	clock_t st, end;
	st = clock();
	int ctr = 0;
	int m, n;
	for(int m = 2; m < sqrt(s/2); m++){
		for(int n = 1; n < m; n++){
			if((m+n)%2 != 1 || gcd(m, n) != 1)
				continue;
			int a = m*m + n*n;
			int b = 2*m*n;
			int c = m*m - n*n;
			int p = a + b + c;
			int k = 1;
			while(k*p <= s){
				arr[k*p]++;
				k++;
			}
		}
	}
	for(int i = 1; i <= s; i++){
		if(arr[i] == 1)
			ctr++;
	}
	end = clock();
	cout << ctr << endl;
	cout << (end - st)*1000/CLOCKS_PER_SEC << "ms" <<endl;
	return 0;
}

