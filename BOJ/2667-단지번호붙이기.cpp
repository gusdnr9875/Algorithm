#include <iostream>
#include <algorithm>
using namespace std;
bool visited[26][26] = { 0 };
char arr[26][26] = { 0 };
int arr2[26][26] = { 0 };
int arr3[26] = { 0 };
int n = 0,cnt=0,temp=0;

int bfs(int orx,int ory,int x,int y) {
	visited[y][x] = 1;
	arr2[orx][ory]++;

	if(arr[y][x+1]=='1'&&visited[y][x+1]==0)
		bfs(orx, ory, x+1, y);
	if (arr[y][x - 1] == '1' && visited[y][x - 1] == 0)
		bfs(orx, ory, x - 1, y);
	if (arr[y +1 ][x ] == '1' && visited[y+1][x ] == 0)
		bfs(orx, ory, x , y+1);
	if (arr[y - 1][x] == '1' && visited[y - 1][x] == 0)
		bfs(orx, ory, x, y - 1);

	return 0;
		
}
int main() {
	int n = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i]+1;


	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (arr[i][j] == '1' && visited[i][j] == 0)
				cnt++, bfs(j,i,j, i);
	cout << cnt << "\n";

	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++)
				for (int r = 1; r <= n; r++)
					if (arr2[i][j] < arr2[k][r]) temp = arr2[i][j], arr2[i][j] = arr2[k][r], arr2[k][r] = temp;
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if(arr2[i][j]!=0) 
				cout << arr2[i][j]<<'\n';
}