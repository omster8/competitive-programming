#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	//input
	int n;
	cin >> n;
	vector<int> adj_list[n+1];
	bool visited[n+1] = {false};
	int dist[n+1] = {0};
	for (int i = 0; i < n+1; i++) {adj_list[i] = vector<int>();}
	for (int i = 1; i <= n; i++) {
		int num_options;
		cin >> num_options;
		for (int j = 0; j < num_options; j++) {int temp; cin >> temp; adj_list[i].push_back(temp);}
	}

	//algorithm
	queue<int> q;
	visited[0] = true;	
	visited[1] = true;
	dist[1] = 1;
	q.push(1);
	priority_queue<int> pq;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		bool has_neighbors = false;
		for (int c : adj_list[n]) {
			has_neighbors = true;
			if (!visited[c]) {
				visited[c] = true;
				dist[c] = dist[n] + 1;
				q.push(c);
			}
		}
		if (!has_neighbors) {pq.push(-dist[n]);}
	}
	bool all_visited = true;
	for (bool b : visited) {if (!b) {all_visited = false; break;}}

	//output
	if (all_visited) {cout << "Y\n";}
	else {cout << "N\n";}
	cout << -pq.top();
}