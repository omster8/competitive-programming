#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int num_test_cases;
	cin >> num_test_cases;
	
	//for each testcase
	for (int i = 0; i < num_test_cases; i++) {
		//input
		int num_pins, num_balls, window;
		cin >> num_pins >> num_balls >> window;
		if (num_balls*window >= num_pins) { //trivial case
			int max_score = 0;
			int curr_pin_score;
			for (int j = 0; j < num_pins; j++) {
				cin >> curr_pin_score;
				max_score += curr_pin_score;
			}
			cout << max_score;
			break;
		}
		vector<int> pins(num_pins);
		vector<int> window_sums(num_pins - window + 1);
		int sum_of_first_window = 0, curr_window_sum_index = 0;
		for (int j = 0; j < num_pins; j++) {
			cin >> pins[j];
			if (j < window) {
				sum_of_first_window += pins[j];
				if (j == window - 1) {window_sums[0] = sum_of_first_window;}
			} else {
				curr_window_sum_index++;
				window_sums[curr_window_sum_index] = window_sums[curr_window_sum_index - 1] + pins[j] - pins[j - window];
			}			
		}

		//algorithm
		vector<vector<int>> dp(num_pins + 1, vector<int>(num_balls + 1));
		for (int j = window; j <= num_pins; j++) {
			for (int k = 1; k <= num_balls; k++) {
				if (k*window == j) {
					int sum = 0;
					for (int l = 0; l < k; l++) {
						sum += window_sums[l*window];
					}
					dp[j][k] = sum;
					break;
				}
				dp[j][k] = max(dp[j-1][k], dp[j-window][k-1] + window_sums[j - window]);
			}
		}	
		cout << dp[num_pins][num_balls] << '\n';
	}
}