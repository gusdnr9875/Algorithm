#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001] = { 0 };
int result = 0, n = 0, m = 0;
string arr[1001];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
			cin >> arr[i];

	for (int i = 0; i < n; i++) {
		dp[i][0] = arr[i][0] - '0';
		result = max(result, dp[i][0]);
	}
	for (int i = 0; i < m; i++) {
		dp[0][i] = arr[0][i] - '0';
		result = max(result, dp[0][i]);
	}

	for (int i = 1; i < n; i++) 
		for (int j = 1; j < m; j++) {
			if (arr[i][j] == '1') {
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]);
				dp[i][j] = min(dp[i][j - 1], dp[i][j]);
				dp[i][j]++;
			}
			if (result < dp[i][j])
				result = dp[i][j];
		}
	cout << result*result << '\n';
}