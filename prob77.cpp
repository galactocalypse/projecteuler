#include <iostream>
#include <cstring>
#include <ctime>

#define LIM 1001

using namespace std;

bool isprime[LIM];

int generatePrimes () {
	memset(isprime, 1, LIM);
	int np = 0;
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i < LIM; i++) {
		if (!isprime[i]) continue;
		np++;
		//cout << i << endl;
		for (int j = i*i; j < LIM; j += i) {
			isprime[j] = 0;
		}
	}
	return np;
}

int countWays (int n, int m){
	if (!n) return 1;
	int ways = 0;
	for (int i = m; i >= 2; i--) {
		if (isprime[i]) {
			int k = i;
			while (n - k >= 0) {
				ways += countWays(n - k, i - 1);
				k += i;
			}
		}
	}
	return ways;
}
	

int main (void) {
	generatePrimes();
	clock_t start = clock();
	int i = 10;
	while (countWays(i, i) < 5000) {
		i ++;
	}
	clock_t end = clock();
	double timeElapsed = double(end - start)/CLOCKS_PER_SEC;
	cout <<  i << ": " << timeElapsed << "s" << endl;

	return 0;
}

