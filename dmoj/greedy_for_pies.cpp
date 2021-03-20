#include <bits/stdc++.h>

using namespace std;

vector<int> pies;
vector<int> extra;
int ma[3001][101][101][2];

//prev_taken 0 if false, 1 if true
int max_sugar(int curr_pie, int extra1, int extra2, int prev_taken) {
	int ma_val = ma[curr_pie][extra1+1][extra2+1][prev_taken];
	if (ma_val != -1) {return ma_val;}
	if (curr_pie >= pies.size()) {
		if (prev_taken == 0 && extra1 <= extra2) {return extra[extra2] + max_sugar(curr_pie,extra1,extra2-1,1);}
		if (prev_taken == 1 && extra1 <= extra2) {return max_sugar(curr_pie,extra1+1,extra2,0);}
		return 0;
	} 
	int ans = 0;
	if (prev_taken == 0) {
		ans = pies[curr_pie] + max_sugar(curr_pie+1,extra1,extra2,1);
		if (extra1 <= extra2) {ans = max(ans,extra[extra2] + max_sugar(curr_pie,extra1,extra2-1,1));}
	} else {
		if (extra1 <= extra2) {ans = max(ans,max_sugar(curr_pie,extra1+1,extra2,0));}
	}
	ans = max(ans, max_sugar(curr_pie+1,extra1,extra2,0));
	ma[curr_pie][extra1+1][extra2+1][prev_taken] = ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(ma, -1, sizeof ma);
	int n, m, temp; cin >> n;
	for (int i = 0; i < n; i++) {cin >> temp; pies.push_back(temp);}
	cin >> m;
	for (int i = 0; i < m; i++) {cin >> temp; extra.push_back(temp);}
	sort(extra.begin(), extra.end());
	
	cout << max_sugar(0, 0, m-1, 0);
}