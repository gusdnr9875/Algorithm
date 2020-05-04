#include <iostream>
using namespace std;
int n = 0, m = 0, result = 0;
bool visited[501] = { 0 };
int arr[10000][2] = { 0 };
int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) 
		cin >> arr[i][0] >> arr[i][1];

	for (int i = 0; i < m; i++) {
		if (arr[i][0] == 1) { //상근이의 친구
			int val = arr[i][1];
			visited[val] = 1; //체크
			for (int j = 0; j < m; j++) {// 상근이 친구의 친구들도 체크
				if (arr[j][0] == val)
					visited[arr[j][1]] = 1;
				else if (arr[j][1] == val)
					visited[arr[j][0]] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (visited[i] == 1) {
			result++;
			
		}
	cout << result - 1 << endl;
}