#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> adj_list[50] = {{}, {6}, {6}, {4,5,6,15}, {3,5,6}, {3,4,6}, {1,2,3,4,5,7}, {6,8}, {7,9}, {8,10,12}, {9,11}, {10,12}, {9,11,13}, {12,14,15}, {13}, {3,13}, {17,18}, {16,18}, {16,17}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}};
	char q;
	while (cin >> q) {
		if (q == 'q') {break;}
		if (q == 'i') {
			int x, y;
			bool already_friends = false;
			cin >> x >> y;
			for (int i : adj_list[x]) {if (i == y) {already_friends = true; break;}}
			if (!already_friends) {
    			adj_list[x].push_back(y);
    			adj_list[y].push_back(x);
			}
		}
		else if (q == 'd') {
			int x, y;
			cin >> x >> y;
			for (int i = 0; i < adj_list[x].size(); i++) {
				if (adj_list[x][i] == y) {adj_list[x].erase(adj_list[x].begin() + i); break;}
			}
			for (int i = 0; i < adj_list[y].size(); i++) {
				if (adj_list[y][i] == x) {adj_list[y].erase(adj_list[y].begin() + i); break;}
			}
		}
		else if (q == 'n') {
			int x;
 			cin >> x;
			cout << adj_list[x].size() << '\n';
		}
		else if (q == 'f') {
			int x;
			cin >> x;
			queue<int> q;
			bool visited[50] = {false};
			int dist[50] = {0};
			visited[x] = true;
			q.push(x);
			bool done = false;
			while (!q.empty()) {
				int n = q.front();
				q.pop();
				for (int i : adj_list[n]) {
					if (!visited[i]) {
						visited[i] = true;
						dist[i] = dist[n] + 1;
						if (dist[1] == 3) {done = true; break;}
						q.push(i);
					}
				}		
				if (done) {break;}
			}	
			int ans = 0;
			for (int i = 1; i < 50; i++) {if (dist[i] == 2) {ans++;}};
			cout << ans << '\n';
		}
		else if (q == 's') {
			int x, y;
			cin >> x >> y;
			queue<int> q;
			bool visited[50] = {false};
			int dist[50] = {0};
			visited[x] = true;
			q.push(x);
			bool done = false;
			while (!q.empty()) {
				int n = q.front();
				q.pop();
				for (int i : adj_list[n]) {
					if (!visited[i]) {
						visited[i] = true;
						dist[i] = dist[n] + 1;
						q.push(i);
						if (i == y) {done = true; break;}
					}
				}
				if (done) {break;}
			}
			if (dist[y] == 0) {cout << "Not connected\n";}
			else {cout << dist[y] << '\n';}
		}		
	}	
}