#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		int n;
		cin >> n;
		vector<pair<int,pair<int,int>>> adj_list[n+1][n+1];
		int el[n+1][n+1];
		for (int i = 1; i <= n; i++) {for (int j = 1; j <= n; j++) {cin >> el[i][j]; adj_list[i][j] = vector<pair<int,pair<int,int>>>(0);}}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i-1 >= 1 && abs(el[i-1][j]-el[i][j]) <= 2) {
					if (el[i][j] > el[1][1] || el[i-1][j] > el[1][1]) {pair<int,pair<int,int>> temp = {1,{i-1,j}}; adj_list[i][j].push_back(temp);}
					else {pair<int,pair<int,int>> temp = {0,{i-1,j}}; adj_list[i][j].push_back(temp);}
				}
				if (i+1 <= n && abs(el[i+1][j]-el[i][j]) <= 2) {
					if (el[i][j] > el[1][1] || el[i+1][j] > el[1][1]) {pair<int,pair<int,int>> temp = {1,{i+1,j}}; adj_list[i][j].push_back(temp);}
					else {pair<int,pair<int,int>> temp = {0,{i+1,j}}; adj_list[i][j].push_back(temp);}
				}
				if (j-1 >= 1 && abs(el[i][j-1]-el[i][j]) <= 2) {
					if (el[i][j] > el[1][1] || el[i][j-1] > el[1][1]) {pair<int,pair<int,int>> temp = {1,{i,j-1}}; adj_list[i][j].push_back(temp);}
					else {pair<int,pair<int,int>> temp = {0,{i,j-1}}; adj_list[i][j].push_back(temp);}
				}
				if (j+1 <= n && abs(el[i][j+1]-el[i][j]) <= 2) {
					if (el[i][j] > el[1][1] || el[i][j+1] > el[1][1]) {pair<int,pair<int,int>> temp = {1,{i,j+1}}; adj_list[i][j].push_back(temp);}
					else {pair<int,pair<int,int>> temp = {0,{i,j+1}}; adj_list[i][j].push_back(temp);}
				}		
			}
		}
		
		int dist[n+1][n+1];
		for (int i = 1; i <= n; i++) {for (int j = 1; j <= n; j++) {dist[i][j] = INT_MAX;}}
		bool processed[n+1][n+1] = {{false}};
		priority_queue<pair<int,pair<int,int>>> pq;
		dist[1][1] = 0;
		pair<int,pair<int,int>> temp = {0,{1,1}};
		pq.push(temp);
		while (!pq.empty()) {
			pair<int,int> p = pq.top().second;
			pq.pop();
			if (processed[p.first][p.second]) {continue;}	
			processed[p.first][p.second] = true;
			for (pair<int,pair<int,int>> d : adj_list[p.first][p.second]) {
				if (dist[p.first][p.second] + d.first < dist[d.second.first][d.second.second]) {
					dist[d.second.first][d.second.second] = dist[p.first][p.second] + d.first;
					pair<int,pair<int,int>> new_d = {-dist[d.second.first][d.second.second], {d.second.first, d.second.second}};
					pq.push(new_d);
				}
			}
		}	

		if (dist[n][n] == INT_MAX) {cout << "CANNOT MAKE THE TRIP\n";}
		else {cout << dist[n][n] << '\n';}
		if (c < t-1) {cout << '\n';}
	}
}