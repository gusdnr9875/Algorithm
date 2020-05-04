#include <iostream>
using namespace std;
int t = 0, n = 0;
int arr[1001] = { 0 };


int main() {
	for (int i = 2; i <= 1000; i++) {
		if (arr[i] == 1) continue;
		for (int j = i + i; j <= 1000; j += i)
			arr[j] = 1;
	}
	
	cin >> t;
	while (t--) {
		bool jud = false;
		cin >> n;
		for (int i = 2; i <= n; i++) {
			if (arr[i] == 1) continue;
			for (int j = 2; j <= n; j++) {
				if (arr[j] == 1) continue;
				for (int k = 2; k <= n; k++) {
					if (arr[k] == 1) continue;

					if ((i + j + k) == n) {
						cout << i << ' ' << j << ' ' << k << endl;
						jud = true;
						break;
					}
				}
				if (jud == true)
					break;
			}
			if (jud == true)
				break;
		}
	
	}
}