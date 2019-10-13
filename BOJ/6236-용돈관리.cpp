#include <iostream>
using namespace std;
int n = 0, m = 0;
int arr[100001] = { 0 };
int result = 1000000000;

void binarysearch(int start, int ended) {
	//cout << start << ' ' << ended << '\n';
	if (start > ended) {
		return;
	}
	int mid = (start + ended) / 2;
	int current = mid, cnt = 1;

	for (int i = 1; i <= n; i++) {

		if (arr[i] > mid ) {
			binarysearch(mid + 1, ended);
			return;
		}
		if (current >= arr[i]) current -= arr[i];
		else current = mid - arr[i], cnt++;
		if (cnt > m) {
			binarysearch(mid + 1, ended);
			return;
		}
	}
	if (result > mid) result = mid;
	binarysearch(start, mid-1);


}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	binarysearch(1, 1000000000);
	cout << result << '\n';
}