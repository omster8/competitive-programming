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

bool all_united(int next[], int dest_cities[], int num_dest) {
	int rep = find_rep(1, next);
	for (int i = 0; i < num_dest; i++) {if (find_rep(dest_cities[i], next) != rep) {return false;}}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int cities, roads, num_dest;
	cin >> cities >> roads >> num_dest;
	priority_queue<pair<int,pair<int,int>>> edge_list;
	int dest_cities[num_dest];
	for (int i = 0; i < roads; i++) {pair<int,pair<int,int>> temp; cin >> temp.second.first >> temp.second.second >> temp.first; edge_list.push(temp);}
	for (int i = 0; i < num_dest; i++) {cin >> dest_cities[i];}

	//algorithm
	bool mst_makeable = true;
	int max_smallest_weight = -1;
	while (mst_makeable) {
		int next[cities+1];
		int size[cities+1];
		for (int i = 1; i <= cities; i++) {next[i] = i; size[i] = 1;}
		priority_queue<pair<int,pair<int,int>>> temp_el = edge_list;
		while (temp_el.top().first != max_smallest_weight && !temp_el.empty()) {
			auto e = temp_el.top();
			temp_el.pop();
			if (!same(e.second.first, e.second.second, next)) {
				unite(e.second.first, e.second.second, next, size);
				if (all_united(next, dest_cities, num_dest)) {max_smallest_weight = e.first; break;}
			}
		}
		if (!all_united(next, dest_cities, num_dest)) {mst_makeable = false;}
	}

	//output
	cout << max_smallest_weight;
}