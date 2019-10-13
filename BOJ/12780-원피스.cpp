#include <iostream>
using namespace std;

int n = 0;
int arr[12] = { 0 };
int giho[4] = { 0 };
int current[12] = { 0 };
long long maxxed = -100000000000, mini = 100000000000;


void sear(int cursor) {
	if (cursor == n) {
		long long sum = arr[0];

		for (int i = 0; i < n - 1; i++) {
			if (current[i] == 0)
				sum += arr[i + 1];
			else if (current[i] == 1)
				sum -= arr[i + 1];
			else if (current[i] == 2)
				sum *= arr[i + 1];
			else if (current[i] == 3)
				sum /= arr[i + 1];
		}
		if (maxxed < sum) maxxed = sum;
		if (mini > sum) mini = sum;

		return;
	}


	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < arr[i]; j++)
		{
			current[cursor] = i;
			sear(cursor + 1);
		}

	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> giho[i];

	cout << maxxed << '\n';
	cout << mini << '\n';

}