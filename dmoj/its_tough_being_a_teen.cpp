#include <bits/stdc++.h>

using namespace std;

vector<int> adj_list[8];
int visited[8] = {false};
int num_visited = 0;

void dfs(int n) {
	if (visited[n]) {return;}
	visited[n] = true;
	num_visited++;
	for (int i : adj_list[n]) {dfs(i);}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; i++) {adj_list[i] = vector<int>();}
	adj_list[7].push_back(1);
	adj_list[4].push_back(1);
	adj_list[1].push_back(2);
	adj_list[4].push_back(3);
	adj_list[5].push_back(3);

	//input
	int first, second;
	while (cin >> first) {
		cin >> second;
		if (first == 0 && second == 0) {break;}
		adj_list[second].push_back(first);
	}

	//algorithm
	vector<int> order(0);
	bool removed[8] = {false};
	bool impossible = false;
	
	for (int k = 0; k < 7; k++) {
		priority_queue<int> starter_nodes;
		for (int i = 1; i < 8; i++) {
			if (!removed[i]) {
				num_visited = 0;
				for (int i = 0; i < 8; i++) {visited[i] = false;}
				dfs(i);
				if (num_visited == 1) {starter_nodes.push(-i);}
			}
		}
		if (starter_nodes.empty()) {impossible = true; break;}
		order.push_back(-starter_nodes.top());
		for (int i = 0; i < 8; i++) {for (int j = 0; j < adj_list[i].size(); j++) {if(adj_list[i][j] == order[order.size()-1]) {adj_list[i].erase(adj_list[i].begin()+j);}}}
		removed[order[order.size()-1]] = true;
	}

	//output
	if (impossible) {cout << "Cannot complete these tasks. Going to bed.";}
	else {
		for (int i : order) {cout << i << " ";}
	}
}