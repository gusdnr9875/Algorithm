#include <iostream>
using namespace std;
int arr[100001][2] = { 0 };
int dp[100001][2] = { 0 };


int main() {
	int t=0,n=0;
	cin >> t;

	while (t--) {

		cin >> n;

		for (int i = 0; i < n; i++) 
			cin >> arr[i][0];
		
		for(int i = 0;i < n; i++)
			cin >> arr[i][1];


		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
		dp[1][0] = arr[1][0] + dp[0][1];
		dp[1][1] = arr[1][1] + dp[0][0];

		for (int i = 2; i < n; i++)
		{
			if (dp[i - 1][0] > dp[i - 2][0]) dp[i][1] = arr[i][1] + dp[i - 1][0];
			else dp[i][1] = arr[i][1] + dp[i - 2][0];

			if (dp[i - 1][1] > dp[i - 2][1]) dp[i][0] = arr[i][0] + dp[i - 1][1];
			else dp[i][0] = arr[i][0] + dp[i - 2][1];
		}
		if (dp[n-1][0] > dp[n-1][1]) cout << dp[n-1][0] << endl;
		else cout << dp[n-1][1] << endl;

	}

}