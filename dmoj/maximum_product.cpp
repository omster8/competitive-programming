#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//input
	int n;
	cin >> n;
	vector<int> cards(n);
	for (int i = 0; i < n; i++) {cin >> cards[i];}

	if (n == 1) {cout << cards[0];} //trivial case
	else {
		//algorithm
		sort(cards.begin(), cards.end());
		int product = 0;
		for (int i = n-1; i >= 0; i--) {
			if (cards[i] > 0 && i == n-1) {product = cards[i];}
			else if (cards[i] > 0) {product *= cards[i];}
			else {break;}
		}
		for (int i = 0; i < n; i += 2) {
			if (product == 0 && cards[i] < 0 && cards[i+1] < 0) {product = 1;}
			if (cards[i] < 0 && cards[i+1] < 0) {product *= cards[i] * cards[i+1];}
			else {break;}
		}

		//output
		cout << product;
	}
}