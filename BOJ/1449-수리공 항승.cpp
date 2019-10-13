#include <iostream>
using namespace std;
int arr[1001] = { 0 };
int dp[1001] = { 0 };

int main() {
	int n, l, num = 0, maxed = 1;
	bool jud = false;
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num] = 1;
	}

	for (int i = 1; i <= 1000; i++) {
		if (i <= l) {
			if (arr[i] == 1 || jud == true)
				dp[i] = 1, jud = true;
			else
				dp[i] = 0;
		}

		else {
			if (arr[i] == 1)
				dp[i] = dp[i-l]+ 1;
			else
				dp[i] = dp[i - 1];
			if (maxed < dp[i]) maxed = dp[i];

		}
	}

	cout <<maxed << endl;

	

}