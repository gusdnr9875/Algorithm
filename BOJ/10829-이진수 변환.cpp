#include <iostream>
using namespace std;
long long n = 0, n_copy = 0;
int cnt = 0;
int main() {
	cin >> n;
	n_copy = n;
	while (n_copy) {
		n_copy /= 2;
		cnt++;   //10ÀÌ¸י 4
		if (n_copy == 1)
			cout << 1;
	}
	for (int i = 1; i < cnt; i++) { //cnt-1¹ר
		n_copy = n;
		for (int j = 1; j < cnt-i; j++) {
			n_copy /= 2;
		}
		cout<< n_copy %2;
	}


	cout << endl;
	return 0;
}