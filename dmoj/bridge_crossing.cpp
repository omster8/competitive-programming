#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //input
  int max_group_len, num_ppl;
  cin >> max_group_len >> num_ppl;
  vector < string > ppl_names(num_ppl);
  vector < int > ppl_times(num_ppl);
  for (int i = 0; i < num_ppl; i++) {
    cin >> ppl_names[i] >> ppl_times[i];
  }

  //algorithm
  if (max_group_len == 1 || num_ppl == 1) { //trivial case
    int sum = 0;
    for (int i: ppl_times) {
      sum += i;
    }
    cout << "Total Time: " << sum << '\n';
    for (string s: ppl_names) {
      cout << s << '\n';
    }
  } else {
    //save all possible max group times
    vector < vector < int >> max_time_in_group(max_group_len, vector < int > (num_ppl));
    for (int i = 0; i < max_group_len; i++) {
      for (int j = 0; j < num_ppl; j++) {
        if (i == 0) {
          max_time_in_group[i][j] = ppl_times[j];
          continue;
        }
        if (i > j) {
          continue;
        }
        max_time_in_group[i][j] = max(max_time_in_group[i - 1][j - 1], ppl_times[j]);
      }
    }

    //dp
    vector < vector < int >> dp(max_group_len + 1, vector < int > (num_ppl + 1));
    vector < int > min_time_first_n_ppl(num_ppl + 1, 10000000);
    vector < int > min_time_group_sizes(num_ppl + 1);
    min_time_first_n_ppl[0] = 0;
    for (int i = 1; i <= num_ppl; i++) {
      for (int j = 1; j <= max_group_len; j++) {
        if (i < j) {
          break;
        }
        dp[j][i] = max_time_in_group[j - 1][i - 1] + min_time_first_n_ppl[i - j];
        if (dp[j][i] < min_time_first_n_ppl[i]) {
          min_time_first_n_ppl[i] = dp[j][i];
          min_time_group_sizes[i] = j;
        }
      }
    }

    //find corresponding groups to the min time
    vector < string > groups;
    int i = num_ppl;
    while (i > 0) {
      for (int j = 0; j < min_time_group_sizes[i]; j++) {
        groups.push_back(ppl_names.back());
        ppl_names.pop_back();
      }
      groups.push_back("new line");
      i -= min_time_group_sizes[i];
    }
    groups.pop_back();
    reverse(groups.begin(), groups.end());

    //output
    cout << "Total Time: " << min_time_first_n_ppl[num_ppl] << '\n';
    for (string s: groups) {
      if (s.compare("new line") == 0) {
        cout << '\n';
      } else {
        cout << s << " ";
      }
    }
  }
}