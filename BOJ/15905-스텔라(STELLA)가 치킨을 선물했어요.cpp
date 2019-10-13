#include <iostream>
using namespace std;
int n = 0, temp = 0, cnt = 0, x = 0;
int arr[66] = { 0 };
int arr2[66] = { 0 };

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i] >> arr2[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i] > arr[j]) temp = arr[i], arr[i] = arr[j], arr[j] = temp;

	x = arr[4];
	
	for (int i = 5;i<n; i++)
	{
		if (x != arr[i])
			break;
		cnt ++;
	}
	cout << cnt << '\n';

}