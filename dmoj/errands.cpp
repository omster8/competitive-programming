#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int houses, roads, errands, start;
	cin >> houses >> roads >> errands >> start;
	vector<int> adj_list[houses + 1];
	bool visited[houses + 1];
	int distances[houses + 1];
	queue<int> q;
	for (int i = 0; i < houses + 1; i++) {adj_list[i] = vector<int>(); visited[i] = false; distances[i] = INT_MAX;}
	for (int i = 0; i < roads; i++) {
		int first, second;
		cin >> first >> second;
		adj_list[first].push_back(second);
		adj_list[second].push_back(first);
	}

	//algorithm
	visited[start] = true;
	distances[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int n = q.front(); q.pop();
		for (int i : adj_list[n]) {
			if (!visited[i]) {
				visited[i] = true;
				distances[i] = min(distances[i], distances[n] + 1);
				q.push(i);
			}
		}
	}

	//output
	for (int i = 0; i < errands; i++) {
		int a, b;
		cin >> a >> b;
		if (visited[a] && visited[b]) {cout << distances[a] + distances[b] << '\n';}
		else {cout << "This is a scam!\n";}
	}
}