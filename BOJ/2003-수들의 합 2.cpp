#include <iostream>
using namespace std;

int arr[10001] = { 0 };
int cnt = 0;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			if (sum == m)
				cnt++;
			else if (sum > m)
				break;
		}

	}

	cout << cnt << endl;

}