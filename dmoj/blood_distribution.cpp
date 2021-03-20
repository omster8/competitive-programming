#include <bits/stdc++.h>

using namespace std;

int num_saved = 0;
vector<int> avail_blood(8);
vector<int> patients(8);

bool take_as_much_as_possible(int avail, int needed) {
	if (avail_blood[avail] >= patients[needed]) {num_saved += patients[needed]; avail_blood[avail] -= patients[needed]; patients[needed] = 0; return true;}
	else {num_saved += avail_blood[avail]; patients[needed] -= avail_blood[avail]; avail_blood[avail] = 0; return false;}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	for (int i = 0; i < 8; i++) {cin >> avail_blood[i];}
	for (int i = 0; i < 8; i++) {cin >> patients[i];}

	//algorithm
	bool successful_or_not;

	//O-
	successful_or_not = take_as_much_as_possible(0,0); 

	//O+
	successful_or_not = take_as_much_as_possible(1,1);
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(0,1);}

	//A-
	successful_or_not = take_as_much_as_possible(2,2);
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(0,2);}

	//A+
	successful_or_not = take_as_much_as_possible(3,3);
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(2,3);}
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(1,3);}
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(0,3);}

	//B-
	successful_or_not = take_as_much_as_possible(4,4);
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(0,4);}

	//B+
	successful_or_not = take_as_much_as_possible(5,5);
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(4,5);}
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(1,5);}
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(0,5);}

	//AB-
	successful_or_not = take_as_much_as_possible(6,6);
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(4,6);}
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(2,6);}
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(0,6);}

	//AB+
	successful_or_not = take_as_much_as_possible(7,7);
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(6,7);}
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(5,7);}
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(4,7);}
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(3,7);}
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(2,7);}
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(1,7);}
	if (!successful_or_not) {successful_or_not = take_as_much_as_possible(0,7);}

	cout << num_saved;
}