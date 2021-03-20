#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//input
	int tiles, rows, cols;
	cin >> tiles >> rows >> cols;
	bool visited[rows+1][cols+1] = {{false}};
	char info[rows+1][cols+1];
	vector<pair<int,int>> adj_list[rows+1][cols+1];
	for (int i = 1; i <= rows; i++) {for (int j = 1; j <= cols; j++) {cin >> info[i][j]; if (info[i][j] == 'I') {visited[i][j] = true;} adj_list[i][j] = vector<pair<int,int>>();}}
	
	//algorithm
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
			if (info[i][j] == 'I') {continue;}
			if (i+1 <= rows && info[i+1][j] == '.') {adj_list[i][j].push_back({i+1,j});}
			if (i-1 >= 1 && info[i-1][j] == '.') {adj_list[i][j].push_back({i-1,j});}
			if (j+1 <= cols && info[i][j+1] == '.') {adj_list[i][j].push_back({i,j+1});}
			if (j-1 >= 1 && info[i][j-1] == '.') {adj_list[i][j].push_back({i,j-1});}
		}
	}	
	priority_queue<int> rooms;
	int num_tiles_in_room = 0;
	bool filled_up = true;
	for (int i = 1; i < sizeof(visited)/sizeof(visited[0]); i++) {for (int j = 1; j < sizeof(visited[0])/sizeof(visited[0][0]); j++) {if (!visited[i][j]) {filled_up = false; break;}} if (!filled_up) {break;}}
	while (!filled_up) {
		num_tiles_in_room = 0;
		int curr_r, curr_c;
		bool done = false;
		for (int i = 1; i <= rows; i++) {for (int j = 1; j <= cols; j++) {if (!visited[i][j]) {curr_r = i; curr_c = j; done = true; break;}} if (done) {break;}}
		queue<pair<int,int>> q;
		visited[curr_r][curr_c] = true;
		num_tiles_in_room++;
		q.push({curr_r,curr_c});
		while (!q.empty()) {
			pair<int,int> n = q.front();
			q.pop();
			for (auto i : adj_list[n.first][n.second]) {
				if (!visited[i.first][i.second]) {
					visited[i.first][i.second] = true;
					num_tiles_in_room++;
					q.push(i);
				}
			}
		}
		rooms.push(num_tiles_in_room);
		filled_up = true;
		for (int i = 1; i < sizeof(visited)/sizeof(visited[0]); i++) {for (int j = 1; j < sizeof(visited[0])/sizeof(visited[0][0]); j++) {if (!visited[i][j]) {filled_up = false; break;}} if (!filled_up) {break;}}
	}
	int rooms_doable = 0;
	while (!rooms.empty()) {
		if (tiles - rooms.top() >= 0) {rooms_doable++; tiles -= rooms.top(); rooms.pop();}
		else {break;}
	}
	
	//output
	if (rooms_doable == 1) {cout << "1 room, " << tiles << " square metre(s) left over";}
	else {cout << rooms_doable << " rooms, " << tiles << " square metre(s) left over";}
}