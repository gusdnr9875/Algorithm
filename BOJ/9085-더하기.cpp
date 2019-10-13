#include <iostream>
using namespace std;
int t = 0;
int n = 0,input = 0;
int sum = 0;
int main() {
	cin >> t;


	while (t--)
	{
		sum = 0;
		cin >> n;
		while (n--) {
			cin >> input;
			sum += input;
		}

		cout << sum << endl;
	}
	return 0;
}