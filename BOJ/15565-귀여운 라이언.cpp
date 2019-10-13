#include <iostream>
using namespace std;
int n = 0, k = 0;

int arr[1000001] = { 0 };
int input = 0;
int arrcnt = 1;
int minn = 1000000000;
int main() {

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		if (input == 1)
			arr[arrcnt++] = i;
	}
	
	for (int i = k; i < arrcnt; i++) {
		if (minn > (arr[i] - arr[i - k + 1]))
			minn = arr[i] - arr[i - k + 1] + 1;

	}
	if (minn == 1000000000)
		cout << -1 << endl;
	else
		cout << minn << endl;
	return 0;
}