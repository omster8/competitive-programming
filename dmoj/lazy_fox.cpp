#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	vector<pair<int,int>> places;
	places.push_back({0,0});
	for (int i = 0; i < n; i++) {
		int a,b; cin >> a >> b;
		places.push_back({a,b});
	}
	vector<pair<int,pair<int,int>>> dist;
	for (int i = 0; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			int sd = pow(places[i].first - places[j].first, 2) + pow(places[i].second - places[j].second, 2);
			pair<int,pair<int,int>> p = {sd, {i,j}};
			dist.push_back(p);
		}
	}
	sort(dist.begin(),dist.end());
	vector<int> most_treats(n+1);
	vector<int> prev_most(n+1);
	vector<int> max_dist(n+1);
	for (auto p : dist) {
		int d = p.first, a = p.second.first, b = p.second.second;
		if (d > max_dist[a]) {
			max_dist[a] = d;
			prev_most[a] = most_treats[a];
		}
		if (d > max_dist[b]) {
			max_dist[b] = d;
			prev_most[b] = most_treats[b];
		}
		most_treats[a] = max(most_treats[a],1+prev_most[b]);
		if (a == 0) {continue;}
		most_treats[b] = max(most_treats[b],1+prev_most[a]);
	}
	cout << most_treats[0];
}