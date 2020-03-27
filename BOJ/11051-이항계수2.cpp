#include <iostream>
using namespace std;

int n = 0, k = 0;
int dp[1002][1002] = { 0 };

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n + 1; i++) {
		dp[i][1] = 1, dp[i][i] = 1;
		for (int j = 2; j <= i - 1; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			dp[i][j] %= 10007;
		}
	}
	cout << dp[n + 1][k + 1] << '\n';
}