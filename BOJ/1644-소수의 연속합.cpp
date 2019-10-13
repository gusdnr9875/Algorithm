#include <iostream>
using namespace std;

int arr[4000001] = { 0 };
int n = 0, sum = 0, cnt = 0;

int main() {
	
	for (int i = 2; i <= 4000000; i++) {
		for (int j = i+i; j <= 4000000; j += i) {
			if (arr[i] == 1) continue;
			arr[j] = 1;
		}
	}

	//n>=2 일때 소수는 0이야 

	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == 1) continue;
		sum = 0;

		for (int j = i; j <= n; j++) {
			if (arr[j] == 1) continue;
			sum += j;
			if (sum > n) break;
			else if (sum == n) {
				cnt++;
				break;
			}
		}
	}

	cout << cnt << '\n';
}