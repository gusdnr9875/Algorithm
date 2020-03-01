#include <iostream>

using namespace std;
long long n = 0, m = 0;
long long cnt2 = 0, cnt5 = 0;

int	count2(int num) {
	int cnt = 0;
	for (int i = 2; num/i>=1 ; i *= 2) {
		cnt += num / i;
	}
	return cnt;
}


int	count5(int num) {
	int cnt = 0;

	for (int i = 5; num / i >= 1; i *= 5) {
		cnt += num / i;
	}
	return cnt;
}
int main() {
	cin >> n >> m;

	cnt5 += count5(n);
	if(m!=0) cnt5 -= count5(m);
	if (n != m) cnt5 -= count5(n - m);

	cnt2 += count2(n);
	if (m!= 0) cnt2 -= count2(m);
	if (n != m) cnt2 -= count2(n - m);

	if (cnt2 < cnt5) cout << cnt2 << '\n';
	else cout << cnt5 << '\n';
		return 0;
}