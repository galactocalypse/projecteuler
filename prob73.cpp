/*
	Think I've got this.
	
	Aha! Easy peasy, japanesey!
	
	Output:
	------
	7295372
	1.59799s
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
	int c = 0;
	for(int i = 1; i <= 12000; i++){
		for(int j = 2*i+1; j <= min(12000, 3*i-1); j++)
			if(gcd(i, j) == 1){
				c++;
				///cout << i << "/" << j << endl;
			}
	}
	cout << c << endl;
	t_end = clock();
	op << (double)(t_end - t_start)/CLOCKS_PER_SEC << "s" << endl;
	cout << op.str();
	return 0;
}

