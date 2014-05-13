/*
	This seems doable.
	Correcto!
	But again, takes ages.
	Output:
	------
	402
	16.2342s
	
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
int len[3000001];
int arr[] = {1,1,2,6,24,120,720,5040, 40320, 362880};
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

int getsum(int n){
	int sum = 0;
	do{
		sum += arr[n%10];
		n /= 10;
	}
	while(n);
	return sum;
}

int findlength(int n){
	int i = n;
	set<int> s;
	s.insert(n);
	do{
		i = getsum(i);
		if(s.find(i) != s.end())
			break;
		s.insert(i);
	}
	while(1);
	return s.size();
}

int main(int argc, char** argv){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	clock_t t_start, t_end;
	t_start = clock();
	int c = 0;
	int l, ml = 0;
	for(int i = 1; i < 1000000; i++){
		l = findlength(i);
		//cout << i << " : " << l << endl;
		if(l == 60)
			c++;
	}
	cout << c << endl;
	t_end = clock();
	op << (double)(t_end - t_start)/CLOCKS_PER_SEC << "s" << endl;
	cout << op.str();
	return 0;
}

