#include <iostream>
#include <algorithm>
using namespace std;

int n = 0, len = 1;
int arr[1001];
int sum = 0;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n); //오름차순 정렬

	for (int i = 0; i <= n; i++) {
		if (arr[i] > sum + 1) {
			break;
		}
		sum += arr[i];

	}

	cout << sum + 1 << endl;
}