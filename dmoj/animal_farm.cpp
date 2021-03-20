#include <bits/stdc++.h>

using namespace std;

int find_rep(int n, int next[]) {
	while (n != next[n]) n = next[n];
	return n;
}

bool same(int a, int b, int next[]) {
	return find_rep(a, next) == find_rep(b, next);
}

void unite(int a, int b, int next[], int size[]) {
	a = find_rep(a, next);
	b = find_rep(b, next);
	if (size[a] >= size[b]) {
		next[b] = a;
		size[a] += size[b];
	} else {
		next[a] = b;
		size[b] += size[a];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int pens; cin >> pens;
	vector<pair<int,pair<int,int>>> edge_list;
	map<pair<int,int>,pair<int,int>> edges; //edge pair to {corresponding pen, weight}
	for (int i = 1; i <= pens; i++) {
		int num_corners; cin >> num_corners;
		int corners[num_corners];
		for (int j = 0; j < num_corners; j++) {cin >> corners[j];}
		int weights[num_corners];
		for (int j = 0; j < num_corners; j++) {cin >> weights[j];}
		for (int j = 0; j < num_corners; j++) {
			int u;
			if (j == num_corners-1) {u = 0;} else {u = j+1;}
			if (edges.find({corners[j],corners[u]}) != edges.end()) {
				pair<int,pair<int,int>> temp = {weights[j],{i,edges[{corners[j],corners[u]}].first}};
				edge_list.push_back(temp);
				edges.erase({corners[j],corners[u]});
			} else if (edges.find({corners[u],corners[j]}) != edges.end()) {
				pair<int,pair<int,int>> temp = {weights[j],{i,edges[{corners[u],corners[j]}].first}};
				edge_list.push_back(temp);
				edges.erase({corners[u],corners[j]});
			} else {
				edges[{corners[j],corners[u]}] = {i,weights[j]};
			}
		}
	}
	for (auto p : edges) {
		pair<int,pair<int,int>> temp = {p.second.second,{p.second.first,0}};
		edge_list.push_back(temp);
	}

	//algorithm
	int next[pens+1];
	int size[pens+1];
	for (int i = 0; i <= pens; i++) {next[i] = i; size[i] = 1;}
	sort(edge_list.begin(), edge_list.end());
	int cost = 0;
	for (auto e : edge_list) {
		if (!same(e.second.first, e.second.second, next)) {unite(e.second.first, e.second.second, next, size); cost += e.first;}
	}

	int next2[pens+1];
	int size2[pens+1];
	for (int i = 1; i <= pens; i++) {next2[i] = i; size2[i] = 1;}
	int cost2 = 0;
	for (auto e : edge_list) {
		if (e.second.first == 0 || e.second.second == 0) {continue;}
		if (!same(e.second.first, e.second.second, next2)) {unite(e.second.first, e.second.second, next2, size2); cost2 += e.first;}
	}

	//output
	cout << min(cost,cost2);
}