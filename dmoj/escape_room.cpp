#include <bits/stdc++.h>

using namespace std;

int rows, cols;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	cin >> rows >> cols;	
	int values[rows+1][cols+1];
	for (int i = 1; i <= rows; i++) {for (int j = 1; j <= cols; j++) {cin >> values[i][j];}}

	//algorithm
	bool visited[rows+1][cols+1] = {{false}};

	queue<pair<int,int>> q;
	visited[1][1] = true;
	q.push({1,1});
	while (!q.empty()) {
		pair<int,int> n = q.front();
		q.pop();
		if (rows < sqrt(values[n.first][n.second]) && cols <= sqrt(values[n.first][n.second])) {continue;}
		int k;
		if (rows > values[n.first][n.second] || cols > values[n.first][n.second]) {k = 1;}
		else {k = min(values[n.first][n.second]/cols, values[n.first][n.second]/rows);}
		for (; k <= sqrt(values[n.first][n.second]); k++) {
			if (values[n.first][n.second] % k == 0) {
				if (k <= rows && values[n.first][n.second]/k <= cols) {
					if (!visited[k][values[n.first][n.second]/k]) {
						visited[k][values[n.first][n.second]/k] = true;
						q.push({k,values[n.first][n.second]/k});
					}
				}
				if (k <= cols && values[n.first][n.second]/k <= rows) {
					if (!visited[values[n.first][n.second]/k][k]) {
						visited[values[n.first][n.second]/k][k] = true;
						q.push({values[n.first][n.second]/k,k});
					}
				}
			}
			if (visited[rows][cols]) {break;}
		}
		if (visited[rows][cols]) {break;}
	}

	//output
	if (visited[rows][cols]) {cout << "yes";}
	else {cout << "no";}
}