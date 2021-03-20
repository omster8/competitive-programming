#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	vector<int> indices(n);
	for (int i = 0; i < n; i++) {cin >> v[i]; indices[v[i] - 1] = i;}

	if (k >= n - 1) {for (int i = n; i >= 1; i--) {cout << i << " ";}} //trivial case
	else {
		//algorithm
		int num_used = 0;
		for (int i = 0; i < n; i++) {
			if (num_used == k) {break;}
			if (i + v[i] == n) {continue;}
			int temp = v[i];
			v[i] = v[indices[n-i-1]];
			v[indices[n-i-1]] = temp;
			indices[temp - 1] = indices[n-i-1];
			num_used++;
		}

		//output
		for (int i = 0; i < n; i++) {cout << v[i] << " ";}
	}
}