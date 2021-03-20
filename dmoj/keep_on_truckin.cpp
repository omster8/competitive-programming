#include <bits/stdc++.h>

using namespace std;

int first_index_greater_than(int n, vector<int> v, int start, bool strictly_greater_than) {
	int k = start - 1;
	for (int jump = v.size()/2; jump >= 1; jump /= 2) {
		while (k + jump < v.size() && v[k + jump] < n) {k += jump;}
	}
	if (k != v.size()-1 && strictly_greater_than && v[k+1] == n) return k+2;
	return k + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> hotels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};	
	
	//input
	int min, max, num_additional, num_hotels = 14;
	cin >> min >> max >> num_additional;
	for (int i = 0; i < num_additional; i++) {
		int temp;	
		cin >> temp;
		hotels.insert(hotels.begin() + first_index_greater_than(temp, hotels, 0, false), temp);
		num_hotels++;
	}
	
	//algorithm
	vector<long long> dp(num_hotels);
	dp[num_hotels - 1] = 1;
	for (int i = num_hotels - 2; i >= 0; i--) {
		int first_poss_dest_index = first_index_greater_than(hotels[i] + min, hotels, i + 1, false);
		if (first_poss_dest_index == num_hotels) continue;
		int last_poss_dest_index = first_index_greater_than(hotels[i] + max, hotels, i + 1, true) - 1;
		if (first_poss_dest_index > last_poss_dest_index) continue;
		for (int j = first_poss_dest_index; j <= last_poss_dest_index; j++) {dp[i] += dp[j];}		
	}

	//output
	cout << dp[0] << '\n';
}