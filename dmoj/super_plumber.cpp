#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int rows, cols;
	while (cin >> rows && cin >> cols) {
		if (rows == 0 && cols == 0) {break;}

		//input
		vector<vector<int>> obstacles_coins(rows+2, vector<int>(cols+1));
		string curr_row;
		for (int i = 1; i <= rows; i++) {
			cin >> curr_row;
			for (int j = 0; j < cols; j++) {
				if (curr_row[j] == '.') {continue;}
				if (curr_row[j] == '*') {obstacles_coins[i][j] = -1;}
				else {obstacles_coins[i][j] = curr_row[j] - '0';}
			}
		}

		//algorithm
		vector<vector<vector<int>>> dp(rows+2, vector<vector<int>>(cols+1, vector<int>(3)));
		dp[rows][cols-1][0] = obstacles_coins[rows][cols-1]; //step right
		dp[rows][cols-1][1] = obstacles_coins[rows][cols-1]; //step down
		dp[rows][cols-1][2] = obstacles_coins[rows][cols-1]; //step up
		for (int i = 0; i <= rows+1; i++) {
			for (int j = 0; j <= 2; j++) {dp[i][cols][j] = -1;}
		}
		for (int i = 0; i < cols; i++) {
			for (int j = 0; j <= 2; j++) {dp[0][i][j] = -1;}
		}
		for (int i = 0; i < cols; i++) {
			for (int j = 0; j <= 2; j++) {dp[rows+1][i][j] = -1;}
		}
		for (int i = cols-1; i >= 0; i--) {
			for (int j = rows; j >= 1; j--) {
				if (j==rows && i==cols-1) {continue;}
				if (obstacles_coins[j][i] == -1) {dp[j][i][0]=-1; dp[j][i][1]=-1; continue;}
				dp[j][i][0] = max(dp[j][i+1][2],max(dp[j][i+1][0],dp[j][i+1][1]));
				dp[j][i][1] = max(dp[j+1][i][0],dp[j+1][i][1]);
				if (dp[j][i][0] != -1) {dp[j][i][0]+=obstacles_coins[j][i];}
				if (dp[j][i][1] != -1) {dp[j][i][1]+=obstacles_coins[j][i];}
			}
			for (int j = 1; j <= rows; j++) {
				if (j==rows && i==cols-1) {continue;}
				if (obstacles_coins[j][i] == -1) {dp[j][i][2]=-1; continue;}
				dp[j][i][2] = max(dp[j-1][i][0],dp[j-1][i][2]);
				if (dp[j][i][2] != -1) {dp[j][i][2] += obstacles_coins[j][i];}
			}
		}

		//output
		cout << max(dp[rows][0][2],max(dp[rows][0][0],dp[rows][0][1])) << '\n';
	}
}