#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//input
	int time, capacity, num_restaurants;
	cin >> time >> capacity >> num_restaurants;
	vector<vector<int>> restaurants(num_restaurants, vector<int>(3));
	for (int i = 0; i < num_restaurants; i++) {
		for (int j = 0; j < 3; j++) {cin >> restaurants[i][j];}
	}
	
	//algorithm
	vector<vector<vector<int>>> dp(capacity + 1, vector<vector<int>>(time + 1, vector<int>(1, 0)));
	int max_value = 0;
	for (int i = 0; i < num_restaurants; i++) {
		if (restaurants[i][2] <= capacity && restaurants[i][1] <= time){
			if (restaurants[i][0] > dp[restaurants[i][2]][restaurants[i][1]][0]) {
				dp[restaurants[i][2]][restaurants[i][1]].clear();	
				dp[restaurants[i][2]][restaurants[i][1]].resize(1);
				dp[restaurants[i][2]][restaurants[i][1]][0] = restaurants[i][0];
				dp[restaurants[i][2]][restaurants[i][1]].push_back(i);
			}
		}
	}
	for (int i = 1; i <= capacity; i++) {
		for (int j = 1; j <= time; j++) {
			if (dp[i][j][0] == 0) {continue;}
			max_value = max(max_value, dp[i][j][0]);
			for (int k = 0; k < num_restaurants; k++) {
				if(!count(dp[i][j].begin()+1,dp[i][j].end(),k)){
					if (i+restaurants[k][2] <= capacity && j+restaurants[k][1] <= time && dp[i+restaurants[k][2]][j+restaurants[k][1]][0] < dp[i][j][0] + restaurants[k][0]) {
						dp[i+restaurants[k][2]][j+restaurants[k][1]].clear();	
						dp[i+restaurants[k][2]][j+restaurants[k][1]].resize(1);
						vector<int> updated(dp[i][j].begin()+1, dp[i][j].end());
						updated.insert(updated.begin(),dp[i][j][0]+restaurants[k][0]);
						updated.push_back(k);
						dp[i+restaurants[k][2]][j+restaurants[k][1]] = vector<int>(updated);
					}
				}
			}
		}
	}
	
	//output
	cout << max_value;	
}