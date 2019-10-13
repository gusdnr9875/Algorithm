#include <iostream>
using namespace std;

int n = 0;
int arr[1001] = { 0 };
int dp[1001] = { 0 };
int lee_sang_hyun_babo = 0;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i]&&dp[i]<dp[j] + 1)
				dp[i] = dp[j] + 1;
		if (lee_sang_hyun_babo < dp[i])
			lee_sang_hyun_babo = dp[i];
	}
	cout << lee_sang_hyun_babo << endl;
}