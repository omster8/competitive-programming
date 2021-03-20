#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while (cin >> n) {
		//input
		if (n == 0) {break;}		
		vector<int> input(n);
		vector<vector<int>> dp(n,vector<int>(n));
		for (int i = 0; i < n; i++) {cin >> input[i];}

		//algorithm
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				int score = 0;
				for (int k = i + 1; k < j; k++) {
					score = max(score, input[i] + input[k] + input[j] + dp[i][k] + dp[k][j]);
				}
				dp[i][j] = score;
			}
		}

		//output
		cout << dp[0][n-1] << '\n';
	}
}