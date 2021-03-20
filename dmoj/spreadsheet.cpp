#include <bits/stdc++.h>

using namespace std;

int dfs(pair<int,int> n, vector<pair<int,int>> adj_list[11][10], bool already_needed[11][10], int values[11][10]) {
	if (values[n.first][n.second] != -2) {return values[n.first][n.second];}
	if (already_needed[n.first][n.second]) {return -1;}
	already_needed[n.first][n.second] = true;
	int ans = 0;
	for (auto c : adj_list[n.first][n.second]) {int temp = dfs(c, adj_list, already_needed, values); if (temp == -1) {values[n.first][n.second] = -1; return -1;} ans += temp;}
	values[n.first][n.second] = ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int values[11][10];
	for (int i = 1; i <= 10; i++) {for (int j = 1; j <= 9; j++) {values[i][j] = -2;}}
	vector<pair<int,int>> adj_list[11][10];
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			string temp;
			cin >> temp;
			if (temp[0] >= 48 && temp[0] <= 57) {values[i][j] = stoi(temp);}
			else {
				for (int k = 0; k < temp.length() - 1; k += 3) {adj_list[i][j].push_back({temp[k]-64,temp[k+1]-48});}
			}
		}
	}

	for (int i = 1; i <= 10; i++) {for (int j = 1; j <= 9; j++) {bool already_needed[11][10] = {{false}}; int gar = dfs({i,j}, adj_list, already_needed, values); if (gar != -1) {cout << gar << " ";} else {cout << "* ";}} cout << '\n';}
}