#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//input
	int n, m;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> m;
	vector<vector<int>> v2(m, vector<int>(2));
	for (int i = 0; i < m; i++) {cin >> v2[i][0] >> v2[i][1];}
	
	//algorithm
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int bigger_index, smaller_index;
		if (v[v2[i][0]-1] > v[v2[i][0]]) {bigger_index = v2[i][0]-1; smaller_index = v2[i][0];}
		else {bigger_index = v2[i][0]; smaller_index = v2[i][0]-1;}
	
		if (v[smaller_index] + v[bigger_index] - v2[i][1] < v[bigger_index]) {
			v[smaller_index] = 0;
		} else {
			ans += v[smaller_index] + v[bigger_index] - v2[i][1];
			v[smaller_index] = 0;
			v[bigger_index] = 0;
		}
	}
	for (int i = 0; i < n; i++) {ans += v[i];}

	//output
	cout << ans;
}