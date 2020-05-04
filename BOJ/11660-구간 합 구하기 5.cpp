#include <iostream>
using namespace std; 
int n = 0, m = 0;
int dp[1025][1025] = { 0 };
int num = 0, x1 = 0, y11 = 0, x2 = 0, y2 = 0;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> num;
			dp[i][j] = num + dp[i][j - 1] ; // 이전행들을 중복해서 더해놓는것 1111 -> 1 2 3 4 이렇게 쌓이겠지
		}
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] += dp[i - 1][j];
	
	while (m--) {
	
		cin >> x1 >> y11 >> x2 >> y2;
		

		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y11 - 1] + dp[x1 - 1][y11 - 1] << '\n';
	}
}