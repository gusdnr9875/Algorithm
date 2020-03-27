#include <iostream>
#include <algorithm>
using namespace std;

int m = 0, n = 0, k =0;
int arr[102][102] = { 0 };
int x, y, x2, y2;

int result[101] = { 0 };
int sum = 0, result_index = 0;
int x_dep[4] = { 1,-1,0,0 };
int y_dep[4] = { 0, 0,-1,1 };

void dfs(int yy, int xx) {
	
	arr[yy][xx] = -1;
	sum++;

	for (int i = 0; i < 4; i++)
	{
		int yyy = yy + y_dep[i];
		int xxx = xx + x_dep[i];

		if (yyy >= 0 && yyy < m && xxx >= 0 && xxx < n) {
			if (arr[yyy][xxx] == 0)
				dfs(yyy, xxx);
		}

	}
	
}
int main() {
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> x >> y >> x2 >> y2;

		for (int j = y; j < y2; j++) {
			for (int u = x; u < x2; u++) {
				arr[j][u] = 1;
			}
		}
	}


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				sum = 0;
				dfs(i, j);
				result[result_index++] = sum;
			}
		}
	}

	sort(result, result + result_index);

	cout << result_index << endl;
	for (int i = 0; i < result_index; i++)
		cout << result[i] << " ";
	cout << endl;
}