#include <iostream>
using namespace std;
int num[10001] = { 0 };
int arr[9] = { 0 };
int visited[9] = { 0 };
int result[9] = { 0 };

int n = 0, m = 0, temp = 0,mcnt=0;

void dfs(int current, int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= m - 1; i++)
			cout << result[i] << ' ';
		cout << result[m] << endl;
	}

	for(int i=0;i<mcnt;i++)
		if()
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		num[temp] = 1;
	}
	for (int i = 1; i <= 10000; i++)
		if (num[i] == 1) arr[mcnt++] = i;

	for (int i = 0; i < mcnt; i++) {
		dfs(i, 1);
	}
}