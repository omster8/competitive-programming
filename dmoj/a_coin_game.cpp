#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//input
	int n;
	while (cin >> n) {
		if (n == 0) {break;}
		vector<int> init(n);
		vector<int> target(n);
		for (int i = 0; i < n; i++) {int temp; cin >> temp; init[i] = 1 << (temp-1); target[i] = 1 << i;}
		if (n == 1) {cout << 0 << '\n'; continue;}
		map<vector<int>,int> dist;
		dist[init] = 0;
		queue<vector<int>> q;
		q.push(init);
		while (!q.empty()) {
			auto s = q.front(); q.pop();
			auto p = s;
			for (int i = 0; i < n; i++) {
				if (__builtin_ctz(s[i]) == 32) {continue;}
				if (i != 0 && (__builtin_ctz(s[i]) < __builtin_ctz(s[i-1]) || __builtin_ctz(s[i-1]) == 32)) {
					auto d = s;
					d[i-1] |= 1 << __builtin_ctz(s[i]); 
					d[i] ^= 1 << __builtin_ctz(s[i]);
					if (dist.find(d) == dist.end()) {
						dist[d] = dist[s] + 1;
						q.push(d);
					}
				}
				if (i != n-1 && (__builtin_ctz(s[i]) < __builtin_ctz(s[i+1]) || __builtin_ctz(s[i+1]) == 32)) {
					auto d = s;
					d[i+1] |= 1 << __builtin_ctz(s[i]); 
					d[i] ^= 1 << __builtin_ctz(s[i]);
					if (dist.find(d) == dist.end()) {
						dist[d] = dist[s] + 1;
						q.push(d);
					}
				}
				if (dist.find(target) != dist.end()) {break;}
			}
			if (dist.find(target) != dist.end()) {break;}			
		}
		
		if (dist.find(target) != dist.end()) {
			cout << dist[target] << '\n';
		} else {
			cout << "IMPOSSIBLE\n";
		}
	}
}