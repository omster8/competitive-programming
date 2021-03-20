#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//input
	int n;
	cin >> n;
	vector<int> saws(n);
	vector<int> logs(n);
	for (int i = 0; i < n; i++) {cin >> saws[i];}
	for (int i = 0; i < n; i++) {cin >> logs[i];}

	//algorithm
	sort(saws.begin(), saws.end());
	sort(logs.rbegin(), logs.rend());
	long long sum = 0;
	for (int i = 0; i < n; i++) {sum += ((long)saws[i])*((long)logs[i]);}

	//output
	cout << sum;
}