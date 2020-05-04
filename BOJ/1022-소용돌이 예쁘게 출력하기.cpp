#include <iostream>
#include <algorithm> // max 함수 사용
#include <cmath> // abs 함수 사용
using namespace std;

int r1, c1, r2, c2;
int map[50][5] = { 0 };
void solve() {
	int MAX = max(max(abs(r1), abs(c1)), max(abs(r2), abs(c2))); // max값을 찾는다.
	int val = 1; //소용돌이에서 값
	if (0 >= r1 && 0 >= c1 && 0 <= r2 && 0 <= c2)
		map[0 - r1][0 - c1] = val;

	int cnt = 0; // 현재의 카운트를 측정
	int y = 0, x = 0; // 좌표를 나타냄

	for (int i = 1; i <= MAX + 1; i++) {

		for (int i = 1; i <= 1 + cnt * 2; i++) {
			val++;
			x++;
			if (y >= r1 && x >= c1 && y <= r2 && x <= c2)
				map[y - r1][x - c1] = val;
		}
		for (int i = 1; i <= 1 + cnt * 2; i++) {
			val++;
			y--;
			if (y >= r1 && x >= c1 && y <= r2 && x <= c2)
				map[y - r1][x - c1] = val;
		}
		for (int i = 1; i <= 2 + cnt * 2; i++) {
			val++;
			x--;
			if (y >= r1 && x >= c1 && y <= r2 && x <= c2)
				map[y - r1][x - c1] = val;
		}
		for (int i = 1; i <= 2 + cnt * 2; i++) {
			val++;
			y++;
			if (y >= r1 && x >= c1 && y <= r2 && x <= c2)
				map[y - r1][x - c1] = val;
		}

		cnt++;
	}



}

int main() {
	cin >> r1 >> c1 >> r2 >> c2;
	solve();

	int h = abs(r2 - r1);
	int w = abs(c2 - c1);

	int MAX = 0;
	
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= w; j++) {
			MAX = max(MAX, map[i][j]);
		}
	}
	
	//int MAX = max(max(map[0][0], map[0][w - 1]), max(map[h - 1][0], map[h - 1][w - 1])  ); // max값을 찾는다.
	int max_degree = 0;
	for (int i = 1; i <= MAX; i *= 10) {
		max_degree++;
	}
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= w; j++) {
			int current_degree = 0;
			for (int k = 1; k <= map[i][j]; k *= 10)
				current_degree++;
			for (int k = current_degree; k < max_degree; k++)
				cout << ' ';

			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

}

/*

#include<cstdio>
int a[50][50], r1, c1, r2, c2, m, s;
int main() {
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			int x = i - r1, y = j - c1;
			if (i - j < 0) {
				if (i + j < 0) a[x][y] = 4 * i*i + i + 1 - j;
				else a[x][y] = 4 * j*j - 3 * j + 1 - i;
			}
			else {
				if (i + j < 0) a[x][y] = 4 * j*j - j + 1 + i;
				else a[x][y] = 4 * i*i + 3 * i + 1 + j;
			}
			if (a[x][y] > m) m = a[x][y];
		}
	}
	for (; m; m /= 10) s++;
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) printf("%*d ", s, a[i][j]);
		puts("");
	}
	return 0;
}

*/