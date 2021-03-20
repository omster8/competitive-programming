#include <bits/stdc++.h>

using namespace std;

int f(vector<int> &num) {
	while (num.size() > 0 && num[0] == 0) {num.erase(num.begin());}
	if (num.size() <= 4) {
		int count = 0;
		for (int i : num) {if (i == 1) {count++;}}
		if (count == 0) {return 0;}
		return 4 - count;
	}
	for (int i = 1; i < num.size() - 1; i++) {if (num[i] == 1) {break;} if (i == num.size() - 2) {return num.size()-2;}} //special case
	bool zero_found = false; 
	int streak_count = 0;
	for (int i = 0; i < num.size(); i++) {
		if (num[i] == 0 && !zero_found) {zero_found = true; num[i] = 1; streak_count++;}
		else if (num[i] == 0) {break;}
		else {streak_count++;}
	}
	if (streak_count >= 4) {
		while (num.size() > 0 && num[0] == 1) {num.erase(num.begin());}	
	}
	return 1 + f(num);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int n;
	cin >> n;
	vector<int> num;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		num.push_back(temp);
	}
	vector<int> num2(num);
	reverse(num2.begin(),num2.end());
	while (num.size() > 0 && num[num.size() - 1] == 0) {num.erase(num.begin()+num.size()-1);}
	while (num2.size() > 0 && num2[num2.size() - 1] == 0) {num2.erase(num2.begin()+num2.size()-1);}
	cout << min(f(num),f(num2));
}