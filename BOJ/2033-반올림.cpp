#include <iostream>
using namespace std;

int n = 0, k = 0;
int num, index = 0;
int left = 0, right = 0;
int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 1) index = i;
	}
	
	if ((n - 1) % (k - 1) == 0)
		cout << (n - 1) / (k - 1) << endl;
	else
		cout << (n - 1) / (k - 1) + 1 << endl;



}