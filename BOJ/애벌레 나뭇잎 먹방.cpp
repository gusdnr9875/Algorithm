#include <iostream>
using namespace std;

int n = 0, k = 0;
int len;
bool jud[1000000001] = { 0 };
int arr[20] = { 0 };
long long sum = 0;
long long s = 1;
int main() {
	cin >> n >> k;
	len = n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		sum += 1 + (n - 1) / arr[i];
		s *= arr[i];
	}
	//cout << sum << endl;
	for (int i = 0; i < k; i++)
		for (int j = i; j < k; j++)
			if (i != j)
				sum -= (1 + (n - 1) / (arr[i] * arr[j]));
	//sum += 1 + (n - 1) / s;

	cout << n-sum  << endl;
}