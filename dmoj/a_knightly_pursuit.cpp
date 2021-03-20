#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<pair<int,int>> adj_list[100][100];
	for (int i = 1; i <= 99; i++) {
		for (int j = 1; j <= 99; j++) {
			adj_list[i][j] = vector<pair<int,int>>();
			if (i+1 <= 99 && j-2 >= 1) {adj_list[i][j].push_back({i+1,j-2});}
			if (i+2 <= 99 && j-1 >= 1) {adj_list[i][j].push_back({i+2,j-1});}
			if (i+1 <= 99 && j+2 <= 99) {adj_list[i][j].push_back({i+1,j+2});}
			if (i+2 <= 99 && j+1 <= 99) {adj_list[i][j].push_back({i+2,j+1});}
			if (i-1 >= 1 && j-2 >= 1) {adj_list[i][j].push_back({i-1,j-2});}
			if (i-2 >= 1 && j-1 >= 1) {adj_list[i][j].push_back({i-2,j-1});}
			if (i-1 >= 1 && j+2 <= 99) {adj_list[i][j].push_back({i-1,j+2});}
			if (i-2 >= 1 && j+1 <= 99) {adj_list[i][j].push_back({i-2,j+1});}
		}
	}
	int cases;
	cin >> cases;
	for (int t = 0; t < cases; t++) {
		int r, c, pr, pc, kr, kc;
		cin >> r >> c >> pr >> pc >> kr >> kc;
		bool visited[r+1][c+1] = {{false}};
		int dist[r+1][c+1] = {{0}};
		queue<pair<int,int>> q;
		visited[kr][kc] = true;
		q.push({kr,kc});
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			for (auto ch : adj_list[p.first][p.second]) {
				if (ch.first > r || ch.second > c) {continue;}
				if (visited[ch.first][ch.second]) {continue;}
				visited[ch.first][ch.second] = true;
				dist[ch.first][ch.second] = dist[p.first][p.second] + 1;
				q.push(ch);
			}
		}
		if (pr == r) {cout << "Loss in 0 knight move(s).\n"; continue;}
		if (pc == kc && kr == pr + 1) {cout << "Stalemate in 0 knight move(s).\n"; continue;}
		bool knight_cant_move = true;
		for (int i = 1; i <= r; i++) {for (int j = 1; j <= c; j++) {if (dist[i][j] != 0) {knight_cant_move = false; break;}} if (!knight_cant_move) {break;}}
		if (knight_cant_move) {cout << "Stalemate in 0 knight move(s).\n"; continue;}
		bool knight_wins = false;
		for (int i = pr + 1; i < r; i++) {if ((dist[i][pc] != 0 || (i == kr && pc == kc)) && (i - pr - dist[i][pc])%2 == 0 && (i - pr - dist[i][pc])/2 >= 0) {cout << "Win in " << i - pr << " knight move(s).\n"; knight_wins = true; break;}}
		if (knight_wins) {continue;}	
		bool knight_ties = false;
		for (int i = pr + 1; i < r; i++) {if ((dist[i+1][pc] != 0 || (i+1 == kr && pc == kc)) && (i - pr - dist[i+1][pc])%2 == 0 && (i - pr - dist[i+1][pc])/2 >= 0) {cout << "Stalemate in " << i - pr << " knight move(s).\n"; knight_ties = true; break;}}
		if (knight_ties) {continue;}
		cout << "Loss in " << r - pr - 1 << " knight move(s).\n";
	}
}