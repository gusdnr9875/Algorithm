#include <iostream>
using namespace std;
int arr[21] = { 0 };
int n = 0;

int dp(int num,int start,int mid,int end) {
	if (num == 0)
		return 0;

	dp(num - 1, start, end, mid);
	cout << start << " " << end << "\n";
	dp(num - 1, mid, start, end);

	return 0;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> n;
	arr[1] = 1;
	for(int i = 2; i <= n; i++)
		arr[i] = arr[i - 1] * 2 + 1;
	cout << arr[n] << "\n";

	dp(n, 1, 2, 3);

	return 0;

}