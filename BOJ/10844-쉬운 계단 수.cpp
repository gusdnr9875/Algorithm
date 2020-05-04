#include <iostream>
using namespace std;
int arr[101][10] = { 0 };
long long result = 0;
int n = 0;
int main() {
	cin >> n;	

	for (int i = 1; i <= 9; i++) // 초기값 설정
		arr[1][i] = 1;
	for (int j = 1; j <= 8; j++)
		arr[2][j] = 2;
	arr[2][9] = 1;

	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			if (j == 1)
				arr[i][j] = (arr[i - 1][j + 1] + arr[i - 2][j]) % 1000000000;
			else if(j==9)
				arr[i][j] = (arr[i - 1][j - 1]) % 1000000000;
			else 
				arr[i][j] = (arr[i - 1][j + 1] + arr[i - 1][j - 1]) % 1000000000;
			
		}
	}

	for (int i = 1; i <= 9; i++) {
		result += arr[n][i];
	}
	result %= 1000000000;

	cout << result << endl;
}