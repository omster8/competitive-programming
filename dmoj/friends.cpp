#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//input
	int n;
	cin >> n;
	unordered_map<int,int> adj_list;
	unordered_map<int,bool> visited;
	unordered_map<int,int> dist;
	for (int i = 0; i < n; i++) {
		int first, second;
		cin >> first >> second;
		adj_list[first] = second;
		visited[first] = false;
		dist[first] = -1;
	}
	int query1, query2;
	while (cin >> query1) {
		cin >> query2;
		if (query1 == 0 && query2 == 0) {break;}
		for (auto &p : visited) {p.second = false;}
		for (auto &p : dist) {p.second = -1;}
		queue<int> q;
		visited[query1] = true;
		q.push(query1);
		while (!q.empty()) {
			int i = q.front();
			q.pop();
			if (!visited[adj_list[i]]) {
				visited[adj_list[i]] = true;
				dist[adj_list[i]] = dist[i] + 1;
				q.push(adj_list[i]);
			}
		}
		if (dist[query2] == -1) {cout << "No\n"; continue;}
		queue<int> q2;
		for (auto &p : visited) {p.second = false;} //the &p accesses it by reference instead of by value so it actually changes it
		visited[query2] = true;
		q2.push(query2);
		while (!q2.empty()) {
			int i = q2.front();
			q2.pop();
			if (!visited[adj_list[i]]) {
				visited[adj_list[i]] = true;
				q2.push(adj_list[i]);
			}
		}
		if (!visited[query1]) {cout << "No\n"; continue;}
		cout << "Yes " << dist[query2] << '\n';
	}
}