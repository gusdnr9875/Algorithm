#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct sw {
	string a;
	string b;
};

bool cmp(sw a, sw b) {
	if (a.a < b.a)
		return true;
	return false;
}
sw arr[100];

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	for (int i = 0; i < tickets.size(); i++)
		tickets[i].size();
		return answer;
}

int main() {
	vector<vector<string>> tickets = { {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"} };
	for (int i = 0; i < tickets.size(); i++) {
		arr[i].a = tickets[i][0];
		arr[i].b = tickets[i][1];
 	}

	sort(arr, arr + 100, cmp);
	cout << tickets.size() << endl;
	for (int i = 0; i < tickets.size(); i++) {
		cout << arr[i].a << ' ' << arr[i].b << endl;
	}
}