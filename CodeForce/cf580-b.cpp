#include <iostream>
using namespace std;
int dp[100000][2] = { 0 }; // -1로 할때 1로 할때
int n = 0,input,cnt=0;
long long mini = 0;
int diff = 1000100000;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input > 0) { //양수
			dp[i][0] = (1 + input);
			dp[i][1] = input - 1;
		}
		else if (input == 0)
		{
			dp[i][0] = 1;
			dp[i][1] = 1;
		}
		else {
			dp[i][0] = (-1 + -1*input);
			dp[i][1] = (1 + -1 * input);
		}
	}

	for (int i = 0; i < n; i++) {
		if (dp[i][0] < dp[i][1]) {
			mini += dp[i][0];
			if (diff > (dp[i][1] - dp[i][0])) diff = dp[i][1] - dp[i][0];
			cnt++;
		}
		else
			mini += dp[i][1];
	}
	cout << diff << endl;
	if (cnt % 2 == 0)
		cout << mini << '\n';
	else
		cout << mini + diff << '\n';
	return 0;
}