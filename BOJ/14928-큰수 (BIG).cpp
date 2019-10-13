#include <iostream>
using namespace std;

int n = 0, num = 0, mi = 1000000, ma = 0, k = 0, sum = 0;
int main() {
	cin >> n >> k;
	while (n--) {
		cin >> num;
		if (mi > num) mi = num;
		if (ma < num) ma = num;
	}
	sum = (mi + ma) / k;

	if ((mi + ma) % k != 0)
		sum++;
	cout << sum << endl;
}