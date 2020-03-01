#include <iostream>
#include <algorithm>
using namespace std;
int n = 0, m = 0;
int arr[8] = { 0 };
int result[9] = { 0 };
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= m - 1; i++)
			cout << result[i] << ' ';
		cout << result[m] << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] >= result[cnt])
		{
			
			result[cnt+1] = arr[i];
			dfs(cnt+ 1);
			result[cnt+1] = arr[i];
			
		}
		
	}
	
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
	
		result[1] = arr[i];
		dfs( 1);
		result[1] = arr[i];
	
	}
}