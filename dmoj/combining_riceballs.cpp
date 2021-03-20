#include <bits/stdc++.h>

using namespace std;

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        //input
        int num_balls, largest_ball = 0;
        cin >> num_balls;
        vector<int> balls(num_balls);
        for (int i = 0; i < num_balls; i++) {cin >> balls[i];}
	
	if (num_balls == 1) {cout << balls[0];} //trivial case
	else {
		//algorithm
		vector<vector<bool>> dp(num_balls, vector<bool>(num_balls, true));
		int first_index = num_balls-1, second_index = num_balls-1, which_diagonal = num_balls-1;
		while (first_index >= 0 && second_index >= 0) {
			if (first_index < second_index) {
				dp[second_index][first_index] = false;
				int a = first_index, b = second_index;
				while (a < b) {
					int sum_a = 0, sum_b = 0;
					for (int i = first_index; i <= a; i++) {sum_a += balls[i];}	
					for (int i = b; i <= second_index; i++) {sum_b += balls[i];}
					if (sum_a == sum_b) {
						dp[second_index][first_index] = dp[a][first_index] && (dp[b-1][a+1] && dp[second_index][b]);
						if (dp[second_index][first_index] == true) {break;}
						a++; b--;
					}
					else if  (sum_a < sum_b) {a++;}
					else {b--;}
				}
			}

			if (dp[second_index][first_index] == true) {
				int sum = 0;
				for (int i = first_index; i <= second_index; i++) {sum+=balls[i];}
				largest_ball = max(largest_ball,sum);
			}
				
		
			if (first_index-1 < 0 || second_index-1 < 0) {
				second_index = num_balls-1;
				which_diagonal--;
				first_index = which_diagonal;
			} else {second_index--; first_index--;}
		}

		//output
		cout << largest_ball;
	}
}