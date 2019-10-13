#include <iostream>
#include <algorithm>
using namespace std;
int arr[10] = { 0 };
int result[10] = { 0 };
int n = 0, m = 0;
int visited[10] = { 0 };
void dfs(int x) {
	if (x == m) {

		for (int i = 0; i < x; i++)
			cout << result[i] << ' ';
		cout << '\n';

		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0) {
			visited[i] = 1;
			result[x] = arr[i];
			dfs(x + 1);

			visited[i] = 0;
		}
	}


}

int main() {
	cin >> n >> m;


	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	dfs(0);


}