#include <iostream>
using namespace std;
int n = 0;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n*2; j++)
			{
				if (j % 2 == 1)
					cout << '*';
				else
					cout << ' ';

			}
		}
		else {
			for (int j = 1; j <= n*2; j++)
			{
				if (j % 2 == 1)
					cout << ' ';
				else
					cout << '*';


			}
		}
		cout << '\n';
	}
}