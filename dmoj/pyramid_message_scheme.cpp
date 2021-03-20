#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//input
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		unordered_map<string,int> names;
		int m, next_avail_num = 1;
		cin >> m;
		vector<vector<int>> adj_list(101);
		for (int j = 0; j < m/2 - 1; j++) {
			string name1, name2;
			cin >> name1 >> name2;
			if (names.find(name1) == names.end()) {names[name1] = next_avail_num; next_avail_num++;}
			if (names.find(name2) == names.end()) {names[name2] = next_avail_num; next_avail_num++;}
			adj_list[names[name1]].push_back(names[name2]);
			adj_list[names[name2]].push_back(names[name1]);
		}
		string name1, name2;
		cin >> name1 >> name2;
		if (names.find(name1) == names.end()) {names[name1] = next_avail_num; next_avail_num++;}
		if (names.find(name2) == names.end()) {names[name2] = next_avail_num; next_avail_num++;}
		adj_list[names[name1]].push_back(names[name2]);
		adj_list[names[name2]].push_back(names[name1]);
		bool visited[names.size() + 1] = {false};
		int dist[names.size() + 1] = {0};
		visited[names[name2]] = true;
		queue<int> q;
		q.push(names[name2]);
		while (!q.empty()) {
			int k =  q.front();
			q.pop();
			for (auto j : adj_list[k]) {
				if (!visited[j]) {
					visited[j] = true;
					dist[j] = dist[k] + 1;
					q.push(j);
				}
			}
		}
		int max_dist = 0;
		for (int j = 1; j <= names.size(); j++) {if (dist[j] >= max_dist) {max_dist = dist[j];}}
		cout << 10*m - 20*max_dist << '\n';
	}
}