#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	vector<int> fav(n);
	for (int i = 0; i < n; i++) {
		cin >> fav[i];
	}
	
	double ans = 0;
	vector<double> dp(n);
	map<int,int> last;
	last[fav[n-1]] = n-1;
	dp[n-1] = 0;
	double sum = 0;
	if (fav[0] == fav[n-1]) {cout << 1;}
	else {
		for (int i = n-2; i > 0; i--) {
			if (last.find(fav[i]) != last.end()) {dp[i] = dp[last[fav[i]]]; sum += dp[i]; continue;}
			if (fav[i] == fav[0]) {dp[i] = 1; last[fav[i]] = i; sum += dp[i]; continue;}
			dp[i] = (1+sum)/(n-i);
			last[fav[i]] = i;
			sum += dp[i];
		}
		cout << (1+sum)/n;
	}
}