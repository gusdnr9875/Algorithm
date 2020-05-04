#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
string val[12];
vector <char> arr[6];

int result = 0;
int x_ar[4] = { 1,-1,0,0 };
int y_ar[4] = { 0,0,1,-1 };
int visited[6][12] = { 0 };

void dfs2(char a, int yy, int xx,int cnt) {
	int sum = cnt;
	
	for (int i = 0; i < 4; i++) {
		int y = yy + y_ar[i];
		int x = xx + x_ar[i];
		if (y >= 0 && y < 6 && x >= 0 && x < 12 && arr[y][x] == arr[yy][xx] && visited[y][x] == 0) {
			sum++;
			visited[y][x] = sum;
			dfs2(a, y, x,sum );

		}
	}
}

void dfs(char a,int yy,int xx) {
	arr[yy][xx] = '8';
	visited[yy][xx] = -1;
	for (int i = 0; i < 4; i++) {
		int y = yy + y_ar[i];
		int x = xx + x_ar[i];
		if (y >= 0 && y < 6 && x >= 0 && x < 12 && arr[y][x] == a && visited[y][x] != -1) {
			dfs(a, y, x);
		
		}
	}
}

bool solve() {
	bool jud = false;
	
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 12; j++) {
			if (arr[i][j] != '.' ) {
				
				memset(visited, 0, sizeof(visited));
				visited[i][j] = 1;
				dfs2(arr[i][j], i, j, 1);
				
				
				for (int u = 0; u < 6; u++)
					for (int m = 0; m < 12; m++)
						if (visited[u][m] >= 4) {
							char word = arr[u][m];
							dfs(word, u, m);
						}
				
			}
		}
	}
	
	for (int i = 0; i < 6; i++)
		for (int j = 0; j< arr[i].size(); j++)
			if (arr[i][j] == '8') {
				jud = true;
				arr[i].erase(arr[i].begin() + j), j--;
			}
	for (int i = 0; i<6; i++)
		if (arr[i].size() < 12) {
			while (arr[i].size() != 12)
				arr[i].push_back('.');
		}

	return jud;
}

int main() {
	for (int i = 0; i < 12; i++) {
		cin >> val[i];
	}
	
	for (int i = 0; i < 6; i++) 
		for (int j = 11; j >= 0; j--)
			arr[i].push_back(val[j][i]);
	
	while (1) {
		bool jud = false;
		
		jud = solve();
		if (jud == false)
			break;
		result++;	

	}
	cout << result << '\n';
}