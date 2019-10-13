#include <iostream>
using namespace std;
int n = 0, m = 0,temp;
int arr[101][3] = { 0 };  //v 무게 c 만족도 k 개수
int dp[101][10001] = { 0 };
int karr[10001][101] = { 0 }; //k 개수를 행마다 적어놓을겁니다. 

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];


	//삽입정렬
	for (int i = 2; i <= n; i++) { 
		for (int j = i - 1; j >= 1; j--) {
			if (arr[j][0] > arr[j + 1][0]) {
				temp = arr[j][0], arr[j][0] = arr[j + 1][0], arr[j + 1][0] = temp;
				temp = arr[j][1], arr[j][1] = arr[j + 1][1], arr[j + 1][1] = temp;
				temp = arr[j][2], arr[j][2] = arr[j + 1][2], arr[j + 1][2] = temp;
			}
			else if (arr[j][0] == arr[j + 1][0] && arr[j][1] < arr[j + 1][1]) {
				temp = arr[j][0], arr[j][0] = arr[j + 1][0], arr[j + 1][0] = temp;
				temp = arr[j][1], arr[j][1] = arr[j + 1][1], arr[j + 1][1] = temp;
				temp = arr[j][2], arr[j][2] = arr[j + 1][2], arr[j + 1][2] = temp;
			}
			else
				break;


		}
	} 

	/*
	for (int i = 1; i <= n; i++)
		cout << arr[i][0] << ' ' << arr[i][1] << ' ' << arr[i][2] << '\n';
	*/
	
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++) {



		}

		


}