#include <bits/stdc++.h>

using namespace std;

void dfs(int n, vector<int> adj_list[], bool visited[]) {
	if (visited[n]) {return;}
	visited[n] = true;
	for (int i : adj_list[n]) {dfs(i, adj_list, visited);}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> adj_list[27];
	for (int i = 1; i <= 26; i++) {adj_list[i] = vector<int>(0);}

	//input
	string in;
	while (cin >> in) {
		if (in[0] == '*') {break;}
		adj_list[(int)(in[0])-64].push_back((int)(in[1])-64);
		adj_list[(int)(in[1])-64].push_back((int)(in[0])-64);
	}

	//algorithm
	int ans = 0;
	vector<string> v;
	for (int i = 1; i <= 26; i++) {
		for (int j = 0; j < adj_list[i].size(); j++) {
			int temp = adj_list[i][j];
			adj_list[i].erase(adj_list[i].begin()+j);
			bool visited[27] = {false};
			dfs(1, adj_list, visited);
			if (!visited[2]) {ans++; v.push_back(string() + char(i+64) + char(temp+64));}
			adj_list[i].insert(adj_list[i].begin() + j, temp);
		}
	}

	//output
	for (string s : v) {cout << s << '\n';}
	cout << "There are " << ans << " disconnecting roads.\n";
}