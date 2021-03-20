#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int length1, length2;
	cin >> length1 >> length2;
	vector<int> v1(length1);
	vector<int> v2(length2);
	for (int i = 0; i < length1; i++) {cin >> v1[i];}
	for (int i = 0; i < length2; i++) {cin >> v2[i];}

	//algorithm
	vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1)); //max length ending at point
	for (int i = 1; i <= length1; i++) {
		for (int j = 1; j <= length2; j++) {
			if (v1[i-1] == v2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;			
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	//output
	cout << dp[length1][length2] << '\n';
}