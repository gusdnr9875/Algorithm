#include <iostream>
#include <algorithm>
using namespace std;
int arr[2000001] = { 0 };
int n = 0, m = 0;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n + m; i++)
		cin >> arr[i];
	sort(arr, arr + (n + m));

	for (int i = 0; i < n + m; i++)
		cout << arr[i]<< " ";
	cout << endl;
}