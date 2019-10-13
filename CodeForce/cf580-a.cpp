#include <iostream>
using namespace std;
int a[101] = { 0 };
int b[101] = { 0 };
int n, m;
int ra = 0, rb = 0;
int main() {
	bool jud = true;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < m; j++)
		{
			jud = true;
			int sum = a[i] + b[j];

			for (int k = 0; k < n; k++) {
				if (a[k] == sum) jud = false;
				break;

			}
			if (jud == true) {
				for (int k = 0; k < m; k++) {
					if (b[k] == sum) jud = false;
					break;
				}
			}
			if (jud == true) {
				ra = a[i], rb = b[j];
				break;
			}

		}
		if (jud == true) {
			break;
		}

	}

	cout << ra << " " << rb << endl;
}