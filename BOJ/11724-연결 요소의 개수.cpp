#include <iostream>
using namespace std;

int n = 0, m = 0, u = 0, v = 0,cnt=0;
int arr[1001][1001] = { 0 };
int cur[1001] = { 0 };
bool visited[1001] = { 0 };

void dfs(int num) {
	if (visited[num] == 1)
		return;
	visited[num] = 1;
	for (int i = 0; i < cur[num]; i++) {
		dfs(arr[num][i]);
	
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		arr[u][cur[u]++] = v;
		arr[v][cur[v]++] = u;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			dfs(i);
			cnt++;
			
		}
	}

	cout << cnt << '\n';
}