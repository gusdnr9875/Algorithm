#include <iostream>
using namespace std;
int n = 0;
bool arr[1200001] = { 0, };
int main() {
	cin >> n;

	for (int i = 2; i <= 1200000; i++) {
		if (arr[i] == true) continue;
		for (int j = i+i; j <= 1200000; j += i) {
			if (arr[j] == true) continue;
			arr[j] = true;
		}
	}

	for (int i = n;; i++) {
		if (arr[i] == true) continue;
		int sized = 1;
		int copy = i;
		bool jud = true;
		while (copy) {
			copy /= 10;
			sized*=10; //2자리수면 100
		}
		sized /= 10;
		copy = i;
		int j = 1;
		while(j<sized) {
			if ((copy / sized % 10) != (copy / j % 10)) jud = false;
			j *= 10;
			sized /= 10;

		}
		if (jud == true) {
			cout << i << endl;
			return 0;
		}

	}
	return 0;
}