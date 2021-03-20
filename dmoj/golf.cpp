#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //input
  int dist, num_clubs;
  cin >> dist >> num_clubs;
  vector < int > clubs(num_clubs);
  for (int i = 0; i < num_clubs; i++) {
    cin >> clubs[i];
  }

  //algorithm
  vector < int > dp(dist + 1, 1000000000);
  dp[0] = 0;
  for (int i = 1; i <= dist; i++) {
    for (int j: clubs) {
      if (i - j >= 0) {
        dp[i] = min(dp[i], 1 + dp[i - j]);
      }
    }
  }

  //output
  if (dp[dist] != 1000000000) {
    cout << "Roberta wins in " << dp[dist] << " strokes.";
  } else {
    cout << "Roberta acknowledges defeat.";
  }
}