#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //input
  int num_pies, num_ppl;
  cin >> num_pies >> num_ppl;

  //trivial cases
  if (num_pies == num_ppl || num_ppl == 1) {
    cout << 1;
  } else {
    //algorithm
    vector < vector < int >> dp(num_pies + 1, vector < int > (num_ppl + 1));
    for (int i = 1; i <= num_pies; i++) {
      for (int j = 1; j <= num_ppl; j++) {
        if (i == j) {
          dp[i][j] = 1;
          break;
        }
        if (j == 1) {
          dp[i][j] = 1;
          continue;
        }
        for (int k = 0; true; k++) {
          if ((i - k - 1) - k * (j - 1) <= 0) {
            break;
          }
          dp[i][j] += dp[(i - k - 1) - k * (j - 1)][j - 1];
        }
      }
    }

    //output
    cout << dp[num_pies][num_ppl];
  }
}