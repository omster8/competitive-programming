#include <bits/stdc++.h>

using namespace std;

int first_index_greater_than(int n, vector<int> v) {
	int k = -1;
	for (int jump = v.size()/2; jump >= 1; jump /= 2) {
		while (k + jump < v.size() && v[k + jump] < n) {k += jump;}
	}
	if (v[k + 1] != n) {return k + 1;}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {cin >> v[i];}
	
	//algorithm
	vector<int> end;
	end.push_back(v[0]);
	for (int i = 1; i < n; i++) {
		if (v[i] > end[end.size() - 1]) {end.push_back(v[i]);}
		else if (first_index_greater_than(v[i], end) != -1) {end[first_index_greater_than(v[i],end)] = v[i];}		
	}

	//output
	cout << end.size();
}