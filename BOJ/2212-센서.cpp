#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001] = { 0 };
int sum = 0;
int main() {
	int n = 0, k = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr+n);
	for (int i = 0; i < n - 1; i++)
		arr[i] = arr[i + 1] - arr[i];
	sort(arr, arr + n - 1); //차이를 오름차순으로 정렬
	for (int i = 0; i < n - k; i++)
		sum += arr[i];

	cout << sum << endl;




}