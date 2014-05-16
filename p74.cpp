/*
	Problem 74
	For once, I manage to beat the MathBlog timing!
	Of course, wouldn't have understood the problem statement itself had it not been for MathBlog.
	Had to determine the size limit for l manually. Using a map was VERY slow. Took about 2360ms on average.

	Anyway, fun problem (now that it has been solved)!
	Output:
	402
	76.852ms
	
	Alright, it's only faster than the MathBlog solution because of the language. The same solution in C# took about 225ms. MathBlog wins. :P

*/
#include<iostream>
#include<map>
#include<ctime>
#include<cstring>
using namespace std;
int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int l[3000001];
int sum(int n){
	int s = 0;
	do{
		s += fact[n%10];
		n /= 10;
	}while(n);
	return s;
}
int findLength(int n){
	//cout << n << endl;
	if(l[n])
		return l[n];
	int s = sum(n);
	if(s == n)
		return l [n] = 1;
	return (l[n] = 1+findLength(sum(n)));
}

int main(){
	clock_t st, end;
	memset(l, 0, sizeof(int)*1000001);
	l[169] = 3;
	l[871] = 2;
	l[872] = 2;
	l[871] = 2;
	l[363601] = 3;
	l[1454] = 3;
	st = clock();
	int lim = 1000000;
	int ctr = 0;
	for(int i = 0; i < lim; i++){
		if(findLength(i) == 60)
			ctr++;
	}
	end = clock();
	cout << ctr << endl;
	cout << ((double)end - st)*1000/CLOCKS_PER_SEC << "ms" << endl;
	return 0;
}

