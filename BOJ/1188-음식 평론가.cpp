#include <iostream>
using namespace std;

int n = 0, m = 0;
int GCD(int a, int b) {
	if (a%b == 0)
		return b;

	return GCD(b, a%b);
}

int main() {
	cin >> n >> m;

	cout << m - GCD(n, m) << endl;
}