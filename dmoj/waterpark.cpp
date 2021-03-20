#include <bits/stdc++.h>

using namespace std;

void dfs(int n, vector<int> adj_list[], bool visited[], int dp[]) {
	if (visited[n]) {return;}
	visited[n] = true;
	for (auto i : adj_list[n]) {dfs(i, adj_list, visited, dp); dp[n] += dp[i];}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int n;
	cin >> n;
	int first, second;
	vector<int> adj_list[n+1];
	bool visited[n+1] = {false};
	int dp[n+1] = {0};
	dp[n] = 1;
	for (int i = 1; i <= n; i++) {adj_list[i] = vector<int>();}
	while (cin >> first) {
		cin >> second;
		if (first == 0 && second == 0) {break;}
		adj_list[first].push_back(second);
	}

	//algorithm
	dfs(1, adj_list, visited, dp);

	//output
	cout << dp[1];
}