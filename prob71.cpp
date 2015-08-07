/*
	This one seems to require paperwork.
	10**12 combinations. We don't have that much time.
	
	Worked out. Kinda.
	We calculate the number of fractions with numberator x that are less than 3/7. We keep track of the largest fraction x/y for every such f that is < 3/7. The final value is our answer.
	Okay, bad logic. Forgot that we need to take into account all reduced fractions, not just ones with prime numerators.
	Never mind. I have another cunning plan... For every x, we find the lowest y such that x/y < 3/7. The largest x/y value is our answer;
	
	Haha. Worked. Didn't expect this to work at the first go.

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

int gcd(int a, int b){
	if(!b)
		return a;
	return gcd(b, a%b);
}

int main(int argc, char** argv){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	clock_t t_start, t_end;
	t_start = clock();
	int maxx = 0, maxy = 0;
	for(int i = 1; i <= 1000000; i++){
		int j = i, x = (int)ceil(7*i/3.0);
		while(gcd(i, x) != 1){
			x++;
			if(x >= 1000000)
				break;
		}
		if(x < 1000000){
			x++;
			if(!maxx || i*maxy > maxx*x){
				maxx = i;
				maxy = x;
			}
		}
	}
	cout << maxx << endl;
	t_end = clock();
	op << (double)(t_end - t_start)/CLOCKS_PER_SEC << "s" << endl;
	cout << op.str();
	return 0;
}

