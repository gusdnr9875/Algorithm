#include <iostream>
using namespace std;
int n = 0, cnt = 0;
int arr[1001] = { 0 };
bool visited[1001] = { 0 };
void dfs(int start,int current) {
	visited[current] = 1;
	if (start == current) {
		cout << current << endl;
		return;
	}
	cout << current << " ";
	dfs(start, arr[current]);
}

void dfs2(int start, int current) {
	visited[current] = 1;
	if (start == current) {	
		return;
	}
	dfs2(start, arr[current]);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		if (visited[i] == 0) {
			cnt++;
			visited[i] = 1;
			dfs2(i, arr[i]);
		}

	cout << cnt << endl;
	for (int i = 1; i <= n; i++)
		visited[i] = 0;

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			cout << i << " ";
			visited[i] = 1;
			dfs(i,arr[i]);
		}
	}
}