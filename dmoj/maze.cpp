#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	//input
	int num_cases;
	cin >> num_cases;
	for (int i = 0; i < num_cases; i++) {
		int rows, cols;
		cin >> rows >> cols;
		vector<pair<int,int>> adj_list[rows+1][cols+1];
		char info[rows+1][cols+1];
		for (int j = 1; j <= rows; j++) {
			for (int k = 1; k <= cols; k++) {
				cin >> info[j][k];	
				if (info[j][k] == '+') {
					adj_list[j][k].push_back({j-1,k});
					adj_list[j][k].push_back({j+1,k});
					adj_list[j][k].push_back({j,k-1});
					adj_list[j][k].push_back({j,k+1});
				} else if (info[j][k] == '|') {
					adj_list[j][k].push_back({j-1,k});
					adj_list[j][k].push_back({j+1,k});
				} else if (info[j][k] == '-') {
					adj_list[j][k].push_back({j,k-1});
					adj_list[j][k].push_back({j,k+1});
				}
			}
		}

		queue<pair<int,int>> q;
		bool visited[rows+1][cols+1] = {{false}};
		int dist[rows+1][cols+1] = {{0}};
		visited[1][1] = true;
		dist[1][1] = 1;
		q.push({1,1});
		while (!q.empty()) {
			pair<int,int> n = q.front();
			q.pop();
			for (auto d : adj_list[n.first][n.second]) {
				if (d.first < 1 || d.first > rows || d.second < 1 || d.second > cols) {continue;}
				if (visited[d.first][d.second]) {continue;}
				if (info[d.first][d.second] == '*') {continue;}
				dist[d.first][d.second] = dist[n.first][n.second] + 1;
				visited[d.first][d.second] = true;
				q.push(d);
			}
		}

		if (!visited[rows][cols]) {cout << -1 << '\n';}
		else {cout << dist[rows][cols] << '\n';}
	}
}