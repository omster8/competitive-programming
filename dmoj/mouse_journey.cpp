#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int r, c, num_cats;
	cin >> r >> c >> num_cats;
	vector<vector<int>> dp(r + 1, vector<int>(c + 1));
	vector<vector<int>> cats(r + 1, vector<int>(c + 1));
	int cat_r, cat_c;
	for (int i = 0; i < num_cats; i++) {
		cin >> cat_r >> cat_c;
		cats[cat_r - 1][cat_c - 1] = -1;
	}

	//algorithm
	dp[r - 1][c - 1] = 1;
	for (int i = r; i >= 1; i--) {
		for (int j = c; j >= 1; j--) {
			if (cats[i - 1][j - 1] == -1 || (i == r && j == c)) {continue;}
			dp[i - 1][j - 1] = dp[i][j - 1] + dp[i - 1][j];
		}
	}
	
	//output
	cout << dp[0][0];
}