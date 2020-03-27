#include <iostream>
using namespace std;
int n = 0, m = 0, x, y,a,b;
int arr[101][2] = { 0 };
int root_x, root_y;
int cnt[101] = { 0 };
bool visited[101] = { 0 };

void bfs() {

	int que[101] = { 0 };
	int started = 0, ended = 0;

	que[ended++] = x;

	while (started != ended) {
		int val = que[started++];
		visited[val] = 1;

		for (int i = 0; i < m; i++) {
			if (arr[i][0] == val && !visited[arr[i][1]]) {
				
				que[ended++] = arr[i][1];
				cnt[arr[i][1]] = cnt[val] + 1;
			}

			if (arr[i][1] == val && !visited[arr[i][0]]) {
				
				que[ended++] = arr[i][0];
				cnt[arr[i][0]] = cnt[val] + 1;
			}

		}


	}

}

int main() {
	cin >> n;
	cin >> x >> y;
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> arr[i][0]>>arr[i][1];
	
	
	
	bfs();
	if (cnt[y]==0) {
		cout << -1 << endl;
		return 0;
	}

	cout << cnt[y] << endl;
	return 0;
}