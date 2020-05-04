#include <iostream>
using namespace std;
int n = 0, result = 0;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i <= 9)
			result += 1;
		else if (i <= 99)
			result += 2;
		else if (i <= 999)
			result += 3;
		else if (i <= 9999)
			result += 4;
		else if (i <= 99999)
			result += 5;
		else if (i <= 999999)
			result += 6;
		else if (i <= 9999999)
			result += 7;
		else if (i <= 99999999)
			result += 8;
		else
			result += 9;
	}
	cout << result << endl;
}