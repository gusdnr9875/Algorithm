#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int main() {
	cin >> n >> m;
	if (n == 1) {
		cout << 1 << endl;
	}
	else if (n == 2) {
		if (m >= 7)
			cout << 4 << endl;
		else
			cout << (m + 1) / 2 << endl;
	}
	else {
		if (m >= 7) {
			cout << m - 2 << endl;
		}
		else {
			cout << min(4, m) << endl;
		}
	}
}