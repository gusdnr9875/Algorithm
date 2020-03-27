#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int n = 0, m = 0;
int arr[183][183] = { 0 };
int visited[183][183] = { 0 };
int que[40000][2] = { 0 };
int started = 0, ended = 0;
int x_go[4] = { 0,0,1,-1 };
int y_go[4] = { 1,-1,0,0 };

void bfs() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 1)
				que[ended][0] = i, que[ended++][1] = j, visited[i][j] = 1;

	while (started != ended) {
		int y = que[started][0];
		int x = que[started++][1];

		for (int i = 0; i < 4; i++) {
			int yyy = y + y_go[i];
			int xxx = x + x_go[i];
			if (yyy >= 0 && yyy < n && xxx >= 0 && xxx < m)
				if (!visited[yyy][xxx]) {
					visited[yyy][xxx] = visited[y][x] + 1;
					que[ended][0] = yyy, que[ended++][1] = xxx;
				}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string arg;
		cin >> arg;
		for (int j = 0; j < m; j++) {
			arr[i][j] = arg[j] - '0';

		}
	}

	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << visited[i][j] - 1 << ' ';
		cout << '\n';
	}
}