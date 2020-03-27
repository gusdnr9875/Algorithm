#include <iostream>
using namespace std;
long long dp[202][202] = { 0 };
int n, k;
long long result = 0;

int main() {
	cin >> n >> k;
	dp[1][n] = 1; // 초기값 설정
	for (int i = 1; i <= k; i++) {		
		for (int j = 0; j <= n; j++) {
			for (int u = j; u <= n; u++)
				dp[i][j] += dp[i - 1][u];
			dp[i][j] %= 1000000000;
		}
	}
	
	for (int i = 0; i <= n; i++)
		result += dp[k][i];
	result %= 1000000000;
	cout << result << endl;
}	