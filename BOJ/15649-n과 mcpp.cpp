#include <iostream>
using namespace std;

int n = 0, m = 0;
int arr[9] = { 0 };
int visited[9] = { 0 };
int result[10] = { 0 };
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i]+1 << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i]==0) {
			visited[i] = 1;
			arr[cnt] = i;
			dfs(cnt + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;

	dfs(0);
}