#include <iostream>
using namespace std;
int n = 0, m = 0;
int arr[501][501] = { 0 };
int result = 0;

void rec1(int x, int y) { //정사각형일때
	int sum = 0;
	if ((x + 1) <= m && (y + 1) <= n)
		sum = arr[y][x] + arr[y + 1][x] + arr[y][x + 1] + arr[y + 1][x + 1];
	if (result < sum) result = sum;


}
void rec2(int x, int y) { // 오이처럼 긴거
	int sum = 0;
	if ((x + 3) <= m) //가로일때
		sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y][x + 3];
	if (result < sum) result = sum;
	sum = 0;
	if ((y + 3) <= n) //세로일때
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 3][x];
	if (result < sum) result = sum;

}

void rec3(int x, int y) { //그 ㄴ모양일때 대칭도 되니까 조심해야해 총 8가지 경우를 비교해줘야지 
	int sum = 0;
	if ((y - 2) >= 1 && (x - 1) >= 1) // ㄱ모양
		sum = arr[y][x] + arr[y -1][x] + arr[y - 2][x] + arr[y - 2][x - 1];
	if (result < sum) result = sum;

	if ((y - 2) >= 1 && (x + 1) <= m) //
		sum = arr[y][x] + arr[y -1][x] + arr[y - 2][x] + arr[y - 2][x + 1];
	if (result < sum) result = sum;

	//위쪽 완료 
	if ((x - 2) >= 1 && (y - 1) >= 1) // L모양
		sum = arr[y][x] + arr[y ][x -1] + arr[y][x - 2] + arr[y - 1][x - 2];
	if (result < sum) result = sum;

	if ((x - 2) >= 1 && (y + 1) <= m) //
		sum = arr[y][x] + arr[y][x - 1] + arr[y][x - 2] + arr[y + 1][x - 2];
	if (result < sum) result = sum;
	//왼쪽완료
	if ((x + 2) <= m && (y - 1) >= 1) // 
		sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y - 1][x + 2];
	if (result < sum) result = sum;

	if ((x + 2) <= m && (y + 1) <= n) // 
		sum = arr[y][x] + arr[y ][x + 1] + arr[y ][x + 2] + arr[y + 1][x + 2];
	if (result < sum) result = sum;
	//오른쪽완료
	if ((y + 2) <= n && (x - 1) >= 1) // 
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x - 1];
	if (result < sum) result = sum;

	if ((y + 2) <= n && (x + 1) <= m) //
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x + 1];
	if (result < sum) result = sum;
	//아래쪽

}


void rec4(int x, int y) { // 4번째 모양을 해보자 총 8개를 구현해야겠지 

	int sum = 0;

	if ((x + 1) <= m && (y + 2) <= n)
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 2][x + 1];
	if (result < sum) result = sum;

	if ((x - 1) >= 1 && (y + 2) <= n)
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y + 2][x - 1];
	if (result < sum) result = sum;

	// 아래로 내려가는거 완료 

	if ((x + 2) <= m && (y - 1) >= 1)
		sum = arr[y][x] + arr[y][x + 1] + arr[y - 1][x + 1] + arr[y - 1][x + 2];
	if (result < sum) result = sum;

	if ((x + 2) <= m && (y + 1) <= n)
		sum = arr[y][x] + arr[y][x + 1] + arr[y + 1][x + 1] + arr[y + 1][x + 2];
	if (result < sum) result = sum;
	//오른쪽으로 치우친거  ㅇㄹ

	if ((x - 1) >= 1 && (y - 2) >= 1)
		sum = arr[y][x] + arr[y - 1][x] + arr[y - 1][x - 1] + arr[y - 2][x - 1];
	if (result < sum) result = sum;

	if ((x + 1) <= m && (y - 2) >= 1)
		sum = arr[y][x] + arr[y - 1][x] + arr[y - 1][x + 1] + arr[y - 2][x + 1];
	if (result < sum) result = sum;

	//위로 치우친거 ㅇㄹ

	if ((x - 2) >= 1 && (y - 1) >= 1)
		sum = arr[y][x] + arr[y][x - 1] + arr[y - 1][x - 1] + arr[y - 1][x - 2];
	if (result < sum) result = sum;

	if ((x - 2) >= 1 && (y + 1) <= n)
		sum = arr[y][x] + arr[y][x - 1] + arr[y + 1][x - 1] + arr[y + 1][x - 2];
	if (result < sum) result = sum;
	//왼쪽으로 치우친거 

}

void rec5(int x, int y) { //대망의 마지막 8개 

	int sum = 0;

	if ((x + 2) <= m && (y - 1) >= 1)
		sum = arr[y][x] + arr[y][x + 1] + arr[y - 1][x + 1] + arr[y][x + 2];
	if (result < sum) result = sum;

	if ((x + 2) <= m && (y + 1) <= n)
		sum = arr[y][x] + arr[y][x + 1] + arr[y + 1][x + 1] + arr[y][x + 2];
	if (result < sum) result = sum;

	// ㅇㄹㅈ ㅇㄹ 

	if ((x - 1) >= 1 && (y - 2) >= 1)
		sum = arr[y][x] + arr[y - 1][x] + arr[y - 1][x - 1] + arr[y - 2][x];
	if (result < sum) result = sum;

	if ((x + 1) <= m && (y - 2) >= 1)
		sum = arr[y][x] + arr[y - 1][x] + arr[y - 1][x + 1] + arr[y - 2][x];
	if (result < sum) result = sum;
	// ㅅㄷ ㅇㄹ

	if ((x - 2) >= 1 && (y - 1) >= 1)
		sum = arr[y][x] + arr[y][x - 1] + arr[y - 1][x - 1] + arr[y][x - 2];
	if (result < sum) result = sum;

	if ((x - 2) >= 1 && (y + 1) <= n)
		sum = arr[y][x] + arr[y][x - 1] + arr[y + 1][x - 1] + arr[y][x - 2];
	if (result < sum) result = sum;


	//ㅇㅉ ㅇㄹ 

	if ((x - 1) >= 1 && (y + 2) <= n)
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y + 2][x];
	if (result < sum) result = sum;

	if ((x + 1) <= m && (y + 2) <= n)
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 2][x];
	if (result < sum) result = sum;
	//ㅎㄷ ㅇㄹ 

}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];


	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			rec1(j, i);
			rec2(j, i);
			rec3(j, i);
			rec4(j, i);
			rec5(j, i);
		}

	cout << result << endl;
	return 0;
}