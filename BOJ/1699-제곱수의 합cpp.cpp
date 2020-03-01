#include <iostream>
#include <cmath>
using namespace std;
int dp[100001] = { 0 };

int main() {
	int n = 0;
	cin >> n;
	dp[0] = 0, dp[1] = 1, dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		int num = pow(i,0.5);
		dp[i] = 1 + dp[i - num*num];
		for (int j = num-1; j >= 1; j--) {
			if( (1 + dp[i - j*j]) < dp[i] )
				dp[i] = 1 + dp[i - j*j];
		}
	}
	cout << dp[n] << endl;
}