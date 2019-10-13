#include <iostream>
using namespace std;

int n = 0, maxx = 0;
int arr[1001] = { 0 };
int dp[1001] = { 0 };


int main() {
	cin >> n;


	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = 1;
		for (int j = 1; j < i; j++)
			if (arr[j] < arr[i] && (dp[j] + 1) > dp[i])
				dp[i] = dp[j] + 1;
	}
	
	for (int i = 1; i <= n; i++)
		if (maxx < dp[i]) maxx = dp[i];

	cout << maxx << '\n';
}