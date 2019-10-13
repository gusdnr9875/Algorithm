#include <iostream>
#include <algorithm>
using namespace std;

int m = 0;
int arr[100001] = { 0 };

int main() {
	int n = 0,cur=0;

	cin >> n;

	m = n;

	for (int i = 0; i < n; i++) {
		cin >> arr[cur++];
		for (int j = 0; j < cur-1; j++)
			if (arr[cur-1] == arr[j]) {
				m--, cur--;
				break;
			}

	}
	sort(arr, arr + m);

	for (int i = 0; i < m; i++) {
		cout << arr[i];
		if (m - 1 != i) cout << " ";
	}
	cout << "\n";
}