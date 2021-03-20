#include <bits/stdc++.h>

using namespace std;

//macro for fast unsigned int input - can't use simultaneously with cin!!!
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main() {
	int cities, roads;
    scan(cities); scan(roads);
	vector<pair<int,int>> adj_list[cities+1];
	for (int i = 1; i <= cities; i++) {adj_list[i] = vector<pair<int,int>>();}
	for (int i = 0; i < roads; i++) {int first, second, w; scan(first); scan(second); scan(w); adj_list[first].push_back({w,second}); adj_list[second].push_back({w,first});}
	int num_sellers;
	scan(num_sellers);
	unordered_map<int,int> sellers;
	for (int i = 0; i < num_sellers; i++) {int city, cost; scan(city); scan(cost); sellers[city] = cost;}
	int start;
	scan(start);
	
	long long dist[cities+1];
	for (int i = 1; i <= cities; i++) {dist[i] = 130000000000;}
	dist[start] = 0;
	bool processed[cities+1] = {false};
	priority_queue<pair<long long,int>> pq;
	pq.push({0,start});
	long long min_price = 130000000000;
	while (!pq.empty()) {
		int n = pq.top().second;
		pq.pop();
		if (processed[n]) {continue;}
		processed[n] = true;
		if (sellers.find(n) != sellers.end()) {
			min_price = min(min_price, sellers[n] + dist[n]);
			sellers.erase(n);
			if (sellers.empty()) {break;}
		}
		for (auto c : adj_list[n]) {
			if (dist[n] + c.first < dist[c.second]) {
				dist[c.second] = dist[n] + c.first;
				pq.push({-dist[c.second],c.second});
			}
		}
	}

	cout << min_price;
}