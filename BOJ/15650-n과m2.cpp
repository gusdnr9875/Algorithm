#include <iostream>
using namespace std;
int n = 0, m = 0;
int arr[8] = { 0 };
int visited[8] = { 0 };

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			bool jud = true;
			visited[i] = 1;

			for (int j = 0; j < cnt; j++)
				if (arr[j] > (i+1)) {
					jud = false;
					break;
				}
			if (jud == true) {
				arr[cnt] = i + 1;
				dfs(cnt + 1);
			}

			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;

	dfs(0);

}