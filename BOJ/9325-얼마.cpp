#include <iostream>
using namespace std;
int t = 0, s = 0, n = 0, q = 0, p = 0;
int sum = 0;


int main() {
	cin >> t;

	while (t--) {
		sum = 0;
		cin >> s;
		sum += s;

		cin >> n;
		while (n--) {
			cin >> q >> p;
			sum += q*p;

		}
		cout << sum << '\n';
	}

}