#include <iostream>
using namespace std;
/*
1번은 회전이 가능한 4가지 경우  -> 아래 오른쪽만 해주면 됨 
3번 부터는 회전이나 대칭을 시키는게 가능하기에 각 8가지 
*/
int n = 0, m = 0, result = 0;
int arr[501][501] = { 0 };

void num1() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= m - 4; j++)
			if ((arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3]) > result) result = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3]);

	for (int i = 0; i < m; i++)
		for (int j = 0; j <= n - 4; j++)
			if ((arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 3][i]) > result) result = (arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 3][i]);
}


void num2() {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			if ((arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]) > result) result = (arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]);

}

void num3() {
	/*
	// 기본 모양
	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j <= n - 3; j++)
			if ((arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 2][i + 1]) > result) result = (arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 2][i + 1]);
	// 기본 대칭
	for (int i = 1; i < m; i++)
		for (int j = 0; j <= n - 3; j++)
			if ((arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 2][i - 1]) > result) result = (arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 2][i - 1]);
	//위로 90도
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= m - 3; j++)
			if ((arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2]) > result) result = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2]);
	//위로 90도 대칭
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j <= m - 3; j++)
			if ((arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]) > result) result = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]);
	// 위로 180도*/
	for (int i = 2; i < n; i++)
		for (int j = 1; j < m; j++)
			if ((arr[i][j] + arr[i - 1][j] + arr[i - 2][j] + arr[i - 2][j - 1]) > result) result = (arr[i][j] + arr[i - 1][j] + arr[i - 2][j] + arr[i - 2][j - 1]);
	// 위로 180도 대칭 

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
	//num1();
	
	//num2();
	cout<< result << endl;
	

}