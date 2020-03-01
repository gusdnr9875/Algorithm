#include <iostream>

using namespace std;

int dp[10001] = { 0 };
int n = 0, k = 0;
int arr[100] = { 0 };
int result = 0;

int main() {

	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		int num = arr[i];
		for (int j = 1; j <= k; j++) {
			if (j >= num) dp[j] += dp[j - num] ;
		}
	}

	cout << dp[k] << endl;
}