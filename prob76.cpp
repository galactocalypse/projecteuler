/*
	Problem 76
	Alright, this should have been a ten minute task. Can't imagine why I'm stuck.
	
	Resuming this after a good two months. I still can't solve this.
	
*/
#include<iostream>
#include<string>
#include<cstring>
#include<sstream>

using namespace std;

long long dp[101];

int main(){
	int n;
	cin >> n;
	dp[0] = 1;
	for(int i = 1; i <= 99; i++){
		for(int j = i; j <= 100; j++){
			dp[j] += dp[j-i];
		}
	}
	cout << dp[n] << endl;
	return 0;
}

