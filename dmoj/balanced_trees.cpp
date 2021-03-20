#include <bits/stdc++.h>

using namespace std;

unordered_map<int,long long> dp;

long long num_trees(int n) {
	if (dp.count(n)) {return dp[n];}
	long long ans = 0;
	for (int j = n/2;;) {
		if (n/j > j) {break;}
		ans += (j - n/(n/j + 1))*num_trees(n/j);
		if (j != n/j) {ans += num_trees(j);}
		j -= j - n/(n/j + 1);
	}
	ans += n - n/2;
	dp[n] = ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//input
	int n;
	cin >> n;
	if (n == 1) {cout << 1;} //trivial case
	else {
		//algorithm
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 2;
		dp[4] = 3;
		dp[5] = 4;
		dp[6] = 6;
		cout << num_trees(n);
	}
}