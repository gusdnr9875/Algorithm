#include <iostream>
#include <cstring>
using namespace std;

int t = 0, k = 0, m = 0, n = 0;
int	arr[51][51];
bool visited[51][51];
int que[2500][2];
int started = 0, ended = 0;
int result = 0;

int x_ar[4] = { -1,1,0,0 };
int y_ar[4] = { 0,0,1,-1 };
void dfs(int y, int x);
void bfs() {

	while (started != ended) {
		
		int x = que[started][0];
		int y = que[started++][1];
		if (visited[y][x] == 1) continue;
		
		result++;

		dfs(y, x);

	}
}
void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int yy = y + y_ar[i];
		int xx = x + x_ar[i];
		if (yy >= 0 && yy < n && xx >= 0 && xx < m) {
			if(arr[yy][xx] == 1 &&visited[yy][xx] == 0)
				dfs(yy, xx);
		}
	}

}

int main() {

	cin >> t;

	while (t--) {

		cin >> m >> n >> k;
		started = 0, ended = 0;
		result = 0;
		memset(arr, 0, sizeof(arr));
		memset(que, 0, sizeof(que));
		memset(visited, 0, sizeof(visited));
		int x, y;

		for (int i = 0; i < k; i++) {
			cin >> que[ended][0] >> que[ended][1];
			arr[que[ended][1]][que[ended][0]] = 1;
			ended++;

		}
		
		bfs();
		
		cout << result << endl;
	}
}