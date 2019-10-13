#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;


	cout << (b % 10)*a << endl;
	int c = ((b / 10) % 10);
	cout << c*a << endl;
	cout << (b / 100)*a << endl;
	cout << a*b << endl;

	return 0;
}