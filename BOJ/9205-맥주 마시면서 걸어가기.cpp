#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
int t = 0, n = 0;
int arr[101][2] = { 0 };
int starting_x, starting_y, destination_x, destination_y;
bool visited[101];
int que[1000000][2] = { 0 };
int started = 0, ended = 0;

void bfs() {
	que[ended][0] = starting_y;
	que[ended++][1] = starting_x;

	while (started != ended) {
		int y = que[started][0];
		int x = que[started++][1];

		for (int i = 0; i <= n; i++) {
			if (!visited[i]) {
				int len_x = min(abs(x - arr[i][1]), abs(arr[i][1] - x));
				int len_y = min(abs(y - arr[i][0]), abs(arr[i][0] - y));
				double len_total = len_x + len_y;
				if (len_total <= 1000)
				{
					visited[i] = 1;
					que[ended][0] = arr[i][0];
					que[ended++][1] = arr[i][1];
				}
				
			}
		}
	}

}
int main() {
	cin >> t;

	while (t--) {
		cin >> n;
		cin >> starting_x >> starting_y;
		for (int i = 0; i < n; i++)
			cin >> arr[i][1] >> arr[i][0];
		cin >> arr[n][1] >> arr[n][0];

		memset(visited, 0, sizeof(visited));
		started = 0, ended = 0;

		bfs();
		if (visited[n])
			cout << "happy" << endl;
		else
			cout << "sad" << endl;
	}


}