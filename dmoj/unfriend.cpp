#include <bits/stdc++.h>

using namespace std;

void dfs(int n, int num_ways_to_prune_tree[], vector<int> adj_list[], bool visited[]) {
	visited[n] = true;
	for (auto i : adj_list[n]) {
		if (!visited[i]) {
			dfs(i,num_ways_to_prune_tree,adj_list,visited);
			num_ways_to_prune_tree[n] *= (num_ways_to_prune_tree[i] + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//input
	int n;
	cin >> n;
	vector<int> adj_list[n+1];
	int num_ways_to_prune_tree[n+1];
	for (int i = 0; i < n+1; i++) {num_ways_to_prune_tree[i] = 1;}
	bool visited[n+1] = {false};
	for (int i = 0; i < n+1; i++) {adj_list[i] = vector<int>(0);}
	for (int i = 1; i <= n-1; i++) {
		int temp;	
		cin >> temp;	
		adj_list[temp].push_back(i);
	}

	//algorithm
	dfs(n,num_ways_to_prune_tree,adj_list,visited);

	//output
	cout << num_ways_to_prune_tree[n];
}