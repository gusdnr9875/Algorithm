#include <iostream>
using namespace std;

int arr[201] = { 0 };
int dp[201] = { 0 };
int n = 0,maxx=0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]&&dp[i]<dp[j]+1)
				dp[i] = dp[j]+1;
		}
		if (maxx < dp[i])
			maxx = dp[i];

	}
	cout << n - maxx << endl;


}