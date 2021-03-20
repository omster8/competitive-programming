#include <bits/stdc++.h>

using namespace std; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int r, c, lonely, overcrowd, born; cin >> r >> c >> lonely >> overcrowd >> born;
	int state = 0;
	char temp; 
	for (int i = 0; i < r*c; i++) {
		cin >> temp;
		if (temp == '*') {
			state |= 1 << (r*c-1 - i);
		}
	}
	
	vector<vector<int>> child(pow(2,r*c),vector<int>());
	for (int i = 1; i < pow(2,r*c)-1; i++) {
		int next_gen = i;
		int which_row = 0;
		for (int j = 0; j < r; j++) {
			for (int k = which_row; k < c+which_row; k++) {
				int alive_neighbors = 0;
				if (k != which_row) {
					if ((i & (1 << (r*c-1 - (k-1)))) != 0) {alive_neighbors++;}
				}
				if (k != which_row+c-1) {
					if ((i & (1 << (r*c-1 - (k+1)))) != 0) {alive_neighbors++;}
				}
				if (j != 0) {
					if ((i & (1 << (r*c-1 - (k-c)))) != 0) {alive_neighbors++;}
				}
				if (j != r-1) {
					if ((i & (1 << (r*c-1 - (k+c)))) != 0) {alive_neighbors++;}
				}
				if (j != 0 && k != c+which_row-1) {
					if ((i & (1 << (r*c-1 - (k-c+1)))) != 0) {alive_neighbors++;}
				}
				if (j != 0 && k != which_row) {
					if ((i & (1 << (r*c-1 - (k-c-1)))) != 0) {alive_neighbors++;}
				}
				if (j != r-1 && k != c+which_row-1) {
					if ((i & (1 << (r*c-1 - (k+c+1)))) != 0) {alive_neighbors++;}
				}
				if (j != r-1 && k != which_row) {
					if ((i & (1 << (r*c-1 - (k+c-1)))) != 0) {alive_neighbors++;}
				}
				if ((i & (1 << (r*c-1 - k))) == 0) {
					if (alive_neighbors > born) {next_gen |= 1 << (r*c-1 - k);}
				} else {
					if (alive_neighbors < lonely || alive_neighbors > overcrowd) {next_gen &= ~(1 << (r*c-1 - k));}
				}
			}
			which_row += c;
		}
		child[next_gen].push_back(i);
	}
	
	//bfs
	queue<int> q;
	vector<bool> visited(pow(2,r*c),false);
	int dist[(int)pow(2,r*c)];
	
	visited[state] = true;
	dist[state] = 0;
	q.push(state);
	bool found = false;
	int ans;
	while (!q.empty()) {
		int s = q.front(); q.pop();
		if (child[s].size() == 0) {found = true; ans = dist[s]; break;}
		for (int i : child[s]) {
			if (visited[i]) {continue;}
			visited[i] = true;
			dist[i] = dist[s]+1;
			q.push(i);
		} 
	}
	
	if (found) {cout << ans << '\n';}
	else {cout << -1 << '\n';}
}