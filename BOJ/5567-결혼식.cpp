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
		if (arr[i][0] == 1) { //������� ģ��
			int val = arr[i][1];
			visited[val] = 1; //üũ
			for (int j = 0; j < m; j++) {// ����� ģ���� ģ���鵵 üũ
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