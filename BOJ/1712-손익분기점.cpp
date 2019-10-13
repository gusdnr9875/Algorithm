#include <iostream>
using namespace std;

int main() {
	long long a = 0, b = 0, c = 0;
	long long cnt = 0;

	cin >> a >> b >> c;

	if (b >= c)
		cout << -1 << '\n';
	else {
		b = c - b;
		cnt = a / b + 1;
		
		
		cout << cnt << '\n';
	}



	return 0;

}