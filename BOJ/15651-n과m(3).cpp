#include <iostream>
using namespace std;

int n = 0, m = 0;
int arr[7] = { 0 };

void dfs(int x) {
	if (x == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[x] = i;
		dfs(x + 1);
	}
}

int main() {
	cin >> n >> m;

	dfs(0);
}