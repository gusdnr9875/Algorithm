#include <iostream>
using namespace std;
int n = 0;
int arr[101][101] = { 0 };
bool visited[101];

void dfs(int y, int x) {
	
	for (int i = 1; i <= n; i++) {
		if (arr[x][i] == 1 && !visited[i]) {
			visited[i] = 1;
			dfs(y, i);
			
		}	
		
	}
	
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			cin >> arr[i][j];
			
	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++)
			visited[j] = 0;

		for (int j = 1; j <= n; j++)
			if (arr[i][j] == 1) {
				visited[j]=1;
				dfs(i, j);
			}

		for (int j = 1; j <= n; j++) {
			if (visited[j] == 1)
				arr[i][j] = 1;
			
		}
	}
	
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}