
#include <iostream>
#include <string>
using namespace std;
int n = 0;
bool ended = 0;
bool isValid(string val) {
	
	int len = val.size();
	int ended = val.size() - 1;

	for (int i = 1; i <= len / 2; i++) {
		string first = val.substr(ended - i, i);
		string second = val.substr(ended, i);
		if (first.compare(second) == 0) return false;
		ended--;
		
	}
	return true;
}

void dfs(int cnt, string val) {
	if (ended == 1)
		return;
	if (!isValid(val))  return;
	if (cnt == n) {
		cout << val <<"\n";
		ended = 1;
		return;
	}

	dfs(cnt + 1, val + '1');

	dfs(cnt + 1, val + '2');

	dfs(cnt + 1, val + '3');

}
int main() {
	cin >> n;
	dfs(0, "");
}