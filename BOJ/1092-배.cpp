#include <iostream>
#include <algorithm>
using namespace std;

int arr_n[51] = { 0 };

int arr_m[10001] = { 0 };

bool visited[10001] = { 0 };
int n = 0, m = 0, result = 0;

bool cmp(int a, int b) {
	if (a >= b)return true;
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr_n[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> arrm[i];

	sort(arr_n, arr_n + n, cmp);
	//sort(arrm, arrm + m, cmp);

	for (int i = 0; i < m; i++)
		cout << arrm[i] << ' ';
	if (arr_n[0] < arrm[0]) {
		cout << -1 << endl;
		return 0;
	}
	
	
	while (1) {
		result++;

		int j = 0;
		for (int i = 0; i < n; i++) {

			while(j<m) {
				if (visited[j] == 1)
					j++;
				else
					break;
			}
			if (arr_n[i] >= arrm[j]) {
				visited[j++] = 1;
			}

		}

		bool jud = false;
		for (int i = 0; i < m; i++)
			if (visited[i] == 0) {
				jud = true;
				break;
			}
		if (jud == false)
			break;

	}
	cout << result << '\n';

}