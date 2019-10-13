#include <iostream>
using namespace std;

long long n = 0;

int main() {
	cin >> n;
	int cnt = 0;

	for (int j = 1; j*j <= n; j++)
			cnt++;
	cout << cnt << '\n';
}