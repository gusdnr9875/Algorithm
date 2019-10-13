#include <iostream>
#include <algorithm>
using namespace std;

int arrn[500001] = { 0 };
int arrm[500001] = { 0 };
bool result[500001];
int n = 0, m = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arrn[i];
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arrm[i];
		result[i] = false;
	}

	sort(arrn, arrn + n); //오름차순으로 정리 

	for (int i = 0; i < m; i++) {
		int left = 0, right = n-1;
		int mid = (n-1)/2; //중간값 

		while (left <= right) {
			mid = (left + right) / 2;
			if (arrn[mid] == arrm[i]) {
				result[i] = true;
				break;
			}
			else if (arrn[mid] > arrm[i])
				right = mid - 1;
			else
				left = mid + 1;

		}
		cout << result[i] << ' ';
	}

	cout << '\n';

}