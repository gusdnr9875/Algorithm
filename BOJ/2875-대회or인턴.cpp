#include <iostream>
using namespace std;
int n, m, k;
int cnt = 0;
int main() {
	cin >> n >> m >> k;

	while (k--) {
		if (n > m * 2)
			n--;
		else if (n == m * 2)
			m--;
		else
			m--;
	}
	while (1) {
		if (n >= 2 && m >= 1)
			n -= 2, m -= 1;
		else
			break;
		cnt++;
	}
	cout << cnt << endl;
}