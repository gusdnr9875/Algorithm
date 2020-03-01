#include <iostream>
using namespace std;

int n, result = 0;
int arr[1001] = { 0 };
int dp[1001] = { 0 };


int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
	
	for (int i = 1; i <= n; i++) {
		int maxed = 0,maxed_index=0;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[j] < arr[i] && maxed < dp[j] )
				maxed = dp[j], maxed_index = j;
		}
		dp[i] = arr[i] + dp[maxed_index];
		if (result < dp[i]) result = dp[i];
	}

	cout << result << endl;
}