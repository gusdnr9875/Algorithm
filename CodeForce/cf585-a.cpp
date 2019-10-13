#include <iostream>
using namespace std;

int a1 = 0, a2 = 0, k1 = 0, k2 = 0, n;
int temp = 0, maxed = 0;

int main() {
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	int n2 = n;

	if (a1 > a2) temp = a1, a1 = a2, a2 = temp, temp = k1, k1 = k2, k2 = temp;//항상 a1작거나 같지

	n2 -= a1*(k1 - 1) + a2*(k2 - 1);
	if (n2 >= 0) cout << n2 << ' ';
	else cout << 0 << ' ';

	while (1) {
		if (a1 > 0 && n >= k1) {
			n -= k1;
			a1--;
		}
		else if (a2 > 0 && n >= k2) {
			n -= k2;
			a2--;
		}
		else
			break;
		maxed++;
	}
	cout << maxed << '\n';

}