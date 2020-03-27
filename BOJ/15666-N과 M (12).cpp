#include <iostream>
#include <algorithm>
using namespace std;

int n = 0, m = 0,arr_index=0,num;
int arr[8] = { 0 };
int result[8];
bool visited[8] = { 0 };
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++)
			cout << result[i] << ' ';
		cout << endl;
		return;
	}

	for (int i = 0; i < arr_index; i++) {
		bool jud = true;

		for (int j = 0; j < cnt; j++)
			if (result[j] > arr[i]) {
				jud = false;
				break;
			}


		if (jud == true)
		{
			result [cnt] = arr[i];
			dfs(cnt + 1);
			//result[cnt] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		bool jud = true;
		cin >> num;
		for (int j = 0; j < arr_index; j++) {
			if (arr[j] == num) {
				jud = false;
				break;
			}
		}
		if (jud == true)
			arr[arr_index++] = num;
	}
	sort(arr, arr + arr_index);
	
	dfs(0);
}