#include <iostream>
using namespace std;

int sum = 0;
int main() {
	int cnt = 0;
	char arr[101];

	cin >> cnt;
	cin >> arr;

	for (int i = 0; arr[i]; i++) {
		sum += arr[i] - 64;
	}
	cout << sum << endl;


}