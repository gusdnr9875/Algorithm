#include <iostream>
using namespace std;

int main() {
	int n = 0;
	long long sum = 0;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;
		sum += a*b;
	}

	cout << sum << endl;
}