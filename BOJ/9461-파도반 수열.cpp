#include <iostream>
using namespace std;

long long dp[101] = { 0 };
int t = 0, n;
int main() {
	dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2;
	for (int i = 5; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];

	cin >> t;

	while (t--) {
		cin >> n;
		cout << dp[n] << endl;
	}
}