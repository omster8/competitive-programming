#include <bits/stdc++.h>

using namespace std;

void dfs(int n, vector<int> adj_list[], bool visited[]) {
	if (visited[n]) {return;}
	visited[n] = true;
	for (int c : adj_list[n]) {dfs(c, adj_list, visited);}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//input
	int p, c;
	cin >> p >> c;
	vector<int> adj_list[p+1];
	for (int i = 1; i <= p; i++) {adj_list[i] = vector<int>();}
	bool visited[p+1] = {false};
	for (int i = 0; i < c; i++) {
		int first, second;
		cin >> first >> second;
		adj_list[first].push_back(second);
	}
	int target1, target2;
	cin >> target1 >> target2;

	//algorithm
	dfs(target1, adj_list, visited);
	if (visited[target2]) {cout << "yes";}
	else {
		for (int i = 0; i <= p; i++) {visited[i] = false;}
		dfs(target2, adj_list, visited);
		if (visited[target1]) {cout << "no";}
		else {cout << "unknown";}
	}
}