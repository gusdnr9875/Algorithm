//insertion sort example

#include <iostream>
using namespace std;

int n = 0, k = 0, temp = 0;
int arr[101][2] = { 0 };
int dp[101][100001] = { 0 };
int maxed = 0;


int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1];
	
	for (int i = 2; i <= n; i++) { //n 
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j][0] > arr[j+1][0]) {
				temp = arr[j][0], arr[j][0] = arr[j+1][0], arr[j+1][0] = temp;
				temp = arr[j][1], arr[j][1] = arr[j+1][1], arr[j+1][1] = temp;
			}
			else if (arr[j][0] == arr[j+1][0] && arr[j][1] < arr[j+1][1]) {
				temp = arr[j][0], arr[j][0] = arr[j + 1][0], arr[j + 1][0] = temp;
				temp = arr[j][1], arr[j][1] = arr[j + 1][1], arr[j + 1][1] = temp;
			}
			else
				break;
			
		}
	} //»ðÀÔÁ¤·Ä
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];

			if (j - arr[i][0] >= 0 && dp[i][j] < (dp[i - 1][j - arr[i][0]] + arr[i][1]))
				dp[i][j] = dp[i - 1][j - arr[i][0]] + arr[i][1];


		}
	}

	cout << dp[n][k] << endl;
}