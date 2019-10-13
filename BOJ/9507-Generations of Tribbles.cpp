#include <iostream>
using namespace std;
long long dp[67] = { 0 };
int t = 0,n=0;
int main() {
	dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i <= 67; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n]<<"\n";}}