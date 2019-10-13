#include <iostream>
using namespace std;

int n = 0;

int main() {
	cin >> n;
	if (n < 100)
		cout << n / 10 + n % 10 << '\n';
	else if (n <= 109)
		cout << n / 10 + n % 10 << '\n';
	else if (n <= 910)
		cout << n / 100 + n % 100 << '\n';
	else 
		cout<< 20 << '\n';


}