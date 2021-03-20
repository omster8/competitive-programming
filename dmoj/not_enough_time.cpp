#include <bits/stdc++.h>

using namespace std;

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        //input
        int n, t;
        cin >> n >> t;
        vector < vector < int >> customer_options(n, vector < int > (6));
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < 6; j++) {
                        cin >> customer_options[i][j];
                }
        }

        //algorithm
        vector < vector < int >> dp(1, vector < int > (t + 1));
        for (int i = 1; i <= n; i++) {
                dp.push_back(vector < int > (t + 1));
                for (int j = 1; j <= t; j++) {
                        dp[1][j] = dp[0][j];
                        if (j - customer_options[i - 1][0] >= 0) {
                                dp[1][j] = max(dp[1][j], customer_options[i - 1][1] + dp[0][j - customer_options[i - 1][0]]);
                        }
                        if (j - customer_options[i - 1][2] >= 0) {
                                dp[1][j] = max(dp[1][j], customer_options[i - 1][3] + dp[0][j - customer_options[i - 1][2]]);
                        }
                        if (j - customer_options[i - 1][4] >= 0) {
                                dp[1][j] = max(dp[1][j], customer_options[i - 1][5] + dp[0][j - customer_options[i - 1][4]]);
                        }
                }
                dp.erase(dp.begin());
        }

        //output
        cout << dp[0][t];
}