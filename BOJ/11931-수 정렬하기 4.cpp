#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001] = { 0 };
int n = 0;

int compare(int &a, int &b) {
	return a > b;
}

int main() {


	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr+n , compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}