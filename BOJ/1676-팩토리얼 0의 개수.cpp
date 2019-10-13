#include <iostream>
using namespace std;
int n = 0;
int arr[2] = { 0 };

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int copy = i;
		while (copy%2==0) {
			copy /= 2;
			arr[0]++;
		}
		while (copy % 5 == 0) {
			copy /= 5;
			arr[1]++;
		}
		
	}
	if (arr[0] < arr[1])
		cout << arr[0] << endl;
	else
		cout << arr[1] << endl;

}