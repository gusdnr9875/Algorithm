#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int n = 0,normal =0,medicine=0;
string arr[100];
bool visited[101][101] = { 0 };
int dex[4] = { 1,-1,0,0 };
int dey[4] = { 0, 0,1,-1 };
void dfs(char color,int x,int y) {

	visited[y][x] = 1;
	
	for (int i = 0; i < 4; i++) {
		int yy = y + dey[i];
		int xx = x + dex[i];
		if (xx >= 0 && xx < n && yy >= 0 && yy< n)
			if (!visited[yy][xx] && arr[yy][xx] == color)
				dfs(color, xx, yy);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for(int i=0;i<n;i++)
		for (int j = 0; j < arr[i].size(); j++) 
			if (!visited[i][j]) {
				dfs(arr[i][j], j, i);
				normal++;
			}

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i<n; i++)
		for (int j = 0; j < arr[i].size(); j++) 
			if (arr[i][j] == 'R') arr[i][j] = 'G';

	for (int i = 0; i<n; i++)
		for (int j = 0; j < arr[i].size(); j++)
			if (!visited[i][j]) {
				dfs(arr[i][j], j, i);
				medicine++;
			}

	cout << normal << ' '<< medicine << endl;
	
}