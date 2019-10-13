#include <iostream>
using namespace std;
int n = 0, m = 0;
int arr[10] = { 0 };


void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++)
			cout << arr[i] << ' ';
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		bool jud = true;

		for (int j = 0; j < cnt; j++) 
			if (arr[j] > i) {
				jud = false;
				break;
			}
		

		if (jud == true)
		{
			arr[cnt] = i;
			dfs(cnt + 1);
		}
	}

}
int main() {
	cin >> n >> m;

	dfs(0);


}