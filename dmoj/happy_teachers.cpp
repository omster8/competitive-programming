#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int num_teachers, time_avail;
	cin >> num_teachers;
	vector<vector<int>> info(num_teachers, vector<int>(3));
	for (int i = 0; i < num_teachers; i++) {
		for (int j = 0; j < 3; j++) {cin >> info[i][j];}
	}
	cin >> time_avail;

	//algorithm
	vector<vector<vector<int>>> dp(num_teachers+1, vector<vector<int>>(time_avail+1, vector<int>(2)));
	for (int i = 1; i <= num_teachers; i++) {
		for (int j = 1; j <= time_avail; j++) {
			dp[i][j][0] = dp[i-1][j][0];
			dp[i][j][1] = dp[i-1][j][1];
			for (int k = 1;;k++) {
				if (j-k*info[i-1][2] < 0) {break;}
				if (dp[i-1][j-k*info[i-1][2]][0] + info[i-1][0]*k - info[i-1][1]*(k-1)*k/2 > dp[i][j][0]) {
					dp[i][j][0] = dp[i-1][j-k*info[i-1][2]][0] + info[i-1][0]*k - info[i-1][1]*(k-1)*k/2;
					dp[i][j][1] = dp[i-1][j-k*info[i-1][2]][1] + k;
				} else if (dp[i-1][j-k*info[i-1][2]][0] + info[i-1][0]*k - info[i-1][1]*(k-1)*k/2 == dp[i][j][0]) {
					dp[i][j][1] = min(dp[i][j][1],dp[i-1][j-k*info[i-1][2]][1] + k);
				}
			}
		}
	}

	//output
	cout << dp[num_teachers][time_avail][0] << '\n' << dp[num_teachers][time_avail][1];
}