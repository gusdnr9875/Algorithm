#include <iostream>
using namespace std;
int arr[51][51] = { 0 };
int n = 0, m = 0;
int r, c, d;
int cnt = 0;
int result = 0;
int main() {
	cin >> n >> m;

	cin >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	while (1) {

		if (cnt == 4) { //2-c,2-d
			if (d == 0)
				if (arr[r + 1][c] == -1) {
					r = r + 1, cnt = 0;
					continue;
				}
				else
					break;

			else if (d == 3)
				if (arr[r][c + 1] == -1) {
					c = c + 1, cnt = 0;
					continue;
				}
				else
					break;
			else if (d == 2)
				if (arr[r - 1][c] == -1) {
					r = r - 1, cnt = 0;
					continue;
				}
				else
					break;
			else if (d == 1)
				if (arr[r ][c-1] == -1) {
					c = c - 1, cnt = 0;
					continue;
				}
				else
					break;

			
		}


		//1.현재 위치를 청소
		if (arr[r][c] == 0) {
		
			arr[r][c] = -1, result++;
		}


		//2번 탐색
		if (d == 0) {//북쪽을 바라볼때
			if (arr[r][c - 1] == 0) //a
				c = c - 1, d = 3,cnt=0;
			else
				d = 3,cnt++; //b
			continue;
		}
		else if (d == 3) {
			if (arr[r + 1][c] == 0) //a
				r = r + 1, d = 2, cnt = 0;
			else
				d = 2, cnt++;
			continue;
		}
		else if (d == 2) {
			if (arr[r][c + 1] == 0) //a
				c = c + 1, d = 1, cnt = 0;
			else
				d = 1, cnt++;
			continue;
		}
		else if (d == 1) {
			if (arr[r-1][c] == 0) //a
				r = r - 1, d = 0,cnt=0;
			else
				d = 0, cnt++;
			continue;
		}
	





	}
	cout << result << endl;

}