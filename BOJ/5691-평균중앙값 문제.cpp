#include <iostream>
using namespace std;
long long a = 0, b = 0, c = 0;
int main() {

	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
	
		cout << 2 * a - b << '\n';
	}

}