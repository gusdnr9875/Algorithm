#include <iostream>
using namespace std;
int dp[1001] = { 0 };
int arr[1001] = { 0 };
int n,num,result =0;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int maxed = 0;
		cin >> arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j] && maxed < dp[j])
				maxed = dp[j];
		}
		dp[i] = maxed + 1;
	}
	
	for (int i = 0; i < n; i++) {
		if (result < dp[i]) result = dp[i];
	}
	cout << result << endl;
}