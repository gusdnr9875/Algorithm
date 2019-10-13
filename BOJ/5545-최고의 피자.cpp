#include <iostream>
using namespace std;

int arr[100];
int n, a, b, c;
int temp = 0;
int sum = 0,sum_cnt;

int main() {
	cin >> n >> a >> b >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[j] < arr[i]) temp = arr[j], arr[j] = arr[i], arr[i] = temp;


	sum = c;
	sum_cnt = a;
	for (int i = 0; i < n; i++) {
		if ((sum / sum_cnt) <= ((sum + arr[i]) / (sum_cnt + b)))
			sum += arr[i], sum_cnt += b;
		else
			break;
	}
	cout << (int)sum / sum_cnt << endl;

}