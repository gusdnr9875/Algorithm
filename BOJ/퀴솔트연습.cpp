#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<int, pair<string, int>> tmp, pair<int, pair<string, int>> tmp2) {
	if (tmp.first < tmp2.first) {
		return true;
	}

	else {
		return false;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, pair<string, int>>> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second.first;
		vec[i].second.second = i;
	}

	stable_sort(vec.begin(), vec.end(), compare);


	for (int i = 0; i < n; i++) {
		cout << vec[i].first << " " << vec[i].second.first << '\n';
	}
}