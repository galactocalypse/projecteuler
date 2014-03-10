/*
	Reference:
	http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion
	
	Weird. 16 numbers apparently never repeat(at least in the range tested, which was 5000 iterations).
	Results:
	Period longer than range for 2629!
	Period longer than range for 3646!
	Period longer than range for 4924!
	Period longer than range for 5692!
	Period longer than range for 5833!
	Period longer than range for 5836!
	Period longer than range for 6172!
	Period longer than range for 6703!
	Period longer than range for 6801!
	Period longer than range for 7389!
	Period longer than range for 7438!
	Period longer than range for 8158!
	Period longer than range for 8287!
	Period longer than range for 8551!
	Period longer than range for 8654!
	Period longer than range for 9103!
	1322 numbers have odd periods.
	16 numbers have periods longer than tested range.
	Time taken: 0.02s

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

int main(int argc, char** argv){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	clock_t t_start, t_end;
	t_start = clock();
	int t, n, i, c = 0, ec = 0;
	//cin >> t;
	t = 10000;
	
	for(int n = 1; n <= t; n++){
		int k = sqrt(n);
		if(k*k == n)continue;

		int tlim = 50000;
		int m[tlim];
		int d[tlim];
		int a[tlim];
		m[0] = 0;
		d[0] = 1;
		a[0] = sqrt(n);

		for(i = 1; i < tlim; i++){
			m[i] = d[i-1]*a[i-1] - m[i-1];
			d[i] = (n - m[i]*m[i])/d[i-1];
			a[i] = (a[0] + m[i])/d[i];
			if(a[i] == 2*a[0])break;
		}
		if(i == 100){
			op << "Period longer than range for "<< n << "!" << endl;
			//printarr(a, i);
			ec++;
		}
		else {
			//op << "Period for " << n << ": " << i << endl;
		}
		if(i&1)
			c++;
	}
	op << c << " numbers have odd periods." << endl;
	op << ec << " numbers have periods longer than tested range." << endl;
	
	t_end = clock();
	op << "Time taken: " << (double)(t_end - t_start)/CLOCKS_PER_SEC << "s" << endl;
	cout << op.str();
	return 0;
}

