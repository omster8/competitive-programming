#include <bits/stdc++.h>

using namespace std;

vector<pair<int,pair<int,int>>> adj_list[101][101];
char in[101][101];

bool can_occupy(int i, int j, int r, int c) {
	if (in[i][j] == 'W' || in[i][j] == 'C') {return false;}
	if (in[i][j] == 'U' || in[i][j] == 'D' || in[i][j] == 'L' || in[i][j] == 'R') {return true;}
	for (int a = i; a <= r; a++) {if (in[a][j] == 'C') {return false;} if (in[a][j] == 'W') {break;}}
	for (int a = i-1; a >= 1; a--) {if (in[a][j] == 'C') {return false;} if (in[a][j] == 'W') {break;}}
	for (int a = j+1; a <= c; a++) {if (in[i][a] == 'C') {return false;} if (in[i][a] == 'W') {break;}}
	for (int a = j-1; a >= 1; a--) {if (in[i][a] == 'C') {return false;} if (in[i][a] == 'W') {break;}}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int r, c;
	cin >> r >> c;
	int start_r, start_c;
	vector<pair<int,int>> empty_spaces;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> in[i][j]; 
			if (in[i][j] == 'S') {start_r = i; start_c = j;} 
			if (in[i][j] == '.') {empty_spaces.push_back({i,j});}
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (!can_occupy(i,j,r,c)) {continue;}
			adj_list[i][j] = vector<pair<int,pair<int,int>>>(0);
			pair<int,pair<int,int>> temp;
			if (in[i][j] == '.' || in[i][j] == 'S') {
				if (i-1 >= 1 && can_occupy(i-1,j,r,c)) {
					temp = {1,{i-1,j}}; adj_list[i][j].push_back(temp);
				}
				if (j-1 >= 1 && can_occupy(i,j-1,r,c)) {
					temp = {1,{i,j-1}}; adj_list[i][j].push_back(temp);
				}
				if (i+1 <= r && can_occupy(i+1,j,r,c)) {
					temp = {1,{i+1,j}}; adj_list[i][j].push_back(temp);
				}
				if (j+1 <= c && can_occupy(i,j+1,r,c)) {
					temp = {1,{i,j+1}}; adj_list[i][j].push_back(temp);
				}
			} 
			else if (in[i][j] == 'U' && i-1 >= 1 && can_occupy(i-1,j,r,c)) {temp = {0,{i-1,j}}; adj_list[i][j].push_back(temp);}
			else if (in[i][j] == 'D' && i+1 <= r && can_occupy(i+1,j,r,c)) {temp = {0,{i+1,j}}; adj_list[i][j].push_back(temp);}
			else if (in[i][j] == 'L' && j-1 >= 1 && can_occupy(i,j-1,r,c)) {temp = {0,{i,j-1}}; adj_list[i][j].push_back(temp);}
			else if (in[i][j] == 'R' && j+1 <= c && can_occupy(i,j+1,r,c)) {temp = {0,{i,j+1}}; adj_list[i][j].push_back(temp);}
		}
	}

	int dist[r+1][c+1];
	for (int i = 1; i <= r; i++) {for (int j = 1; j <= c; j++) {dist[i][j] = INT_MAX;}}
	dist[start_r][start_c] = 0;
	priority_queue<pair<int,pair<int,int>>> pq;	
	pair<int,pair<int,int>> start = {0,{start_r,start_c}};
	pq.push(start);
	bool processed[r+1][c+1] = {{false}};
	while (!pq.empty()) {
		pair<int,int> n = pq.top().second;
		pq.pop();
		if (processed[n.first][n.second]) {continue;}
		processed[n.first][n.second] = true;
		for (pair<int,pair<int,int>> ch : adj_list[n.first][n.second]) {
			if (dist[n.first][n.second] + ch.first < dist[ch.second.first][ch.second.second]) {
				dist[ch.second.first][ch.second.second] = dist[n.first][n.second] + ch.first;
				pair<int,pair<int,int>> temp = {-dist[ch.second.first][ch.second.second],{ch.second.first,ch.second.second}};
				pq.push(temp);
			}
		}
	}
	for (auto p : empty_spaces) {if (dist[p.first][p.second] == INT_MAX) {cout << -1 << '\n';} else {cout << dist[p.first][p.second] << '\n';}}
}