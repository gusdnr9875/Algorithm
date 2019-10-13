#include <stdio.h>

int n = 0, maxx = 0;
int arr[100001] = { 0 };
int dp[100001][2] = { 0 };

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	dp[0][0] = 1, dp[0][1] = 1;

	for (int i = 1; i < n;i++) {
		if (arr[i] >= arr[i - 1]) dp[i][0] = dp[i - 1][0] + 1;
		else dp[i][0] = 1;
		if(arr[i] <= arr[i - 1]) dp[i][1] = dp[i - 1][1] + 1;
		else dp[i][1] = 1;

		if (maxx < dp[i][0])maxx = dp[i][0];
		if (maxx < dp[i][1]) maxx = dp[i][1];
	}

	printf("%d\n", maxx);
	return 0;
}