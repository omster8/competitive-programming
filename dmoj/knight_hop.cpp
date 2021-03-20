#include <bits/stdc++.h>

using namespace std;

bool in_bounds(int x, int y) {
	return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	//input
	pair<int,int> start;
	pair<int,int> end;
	cin >> start.first >> start.second >> end.first >> end.second;
	
	//algorithm
	vector<pair<int,int>> adj_list[9][9];
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (in_bounds(i+2,j+1)) {adj_list[i][j].push_back({i+2,j+1}); adj_list[i+2][j+1].push_back({i,j});}
			if (in_bounds(i+1,j+2)) {adj_list[i][j].push_back({i+1,j+2}); adj_list[i+1][j+2].push_back({i,j});}
			if (in_bounds(i+2,j-1)) {adj_list[i][j].push_back({i+2,j-1}); adj_list[i+2][j-1].push_back({i,j});}
			if (in_bounds(i+1,j-2)) {adj_list[i][j].push_back({i+1,j-2}); adj_list[i+1][j-2].push_back({i,j});}
			if (in_bounds(i-2,j-1)) {adj_list[i][j].push_back({i-2,j-1}); adj_list[i-2][j-1].push_back({i,j});}
			if (in_bounds(i-1,j+2)) {adj_list[i][j].push_back({i-1,j+2}); adj_list[i-1][j+2].push_back({i,j});}
			if (in_bounds(i-2,j-1)) {adj_list[i][j].push_back({i-2,j-1}); adj_list[i-2][j-1].push_back({i,j});}
			if (in_bounds(i-1,j-2)) {adj_list[i][j].push_back({i-1,j-2}); adj_list[i-1][j-2].push_back({i,j});}
		}
	}

	queue<pair<int,int>> q;
	bool visited[9][9] = {{false}};
	int dist[9][9];
	visited[start.first][start.second] = true;
	q.push({start.first,start.second});
	dist[start.first][start.second] = 0;
	while (!q.empty()) {
		pair<int,int> n = q.front();
		q.pop();
		for (auto e : adj_list[n.first][n.second]) {
			if (!visited[e.first][e.second]) {
				visited[e.first][e.second] = true;
				dist[e.first][e.second] = dist[n.first][n.second] + 1;
				q.push(e);
			}
		}
	}

	//output
	cout << dist[end.first][end.second];
}