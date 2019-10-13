#include <iostream>
using namespace std;

char arr[1001][1001]; //1001*1001
int visited[1001][1001]; 
int que[1000000][2] = { 0 };

int n = 0, m = 0;
int start = 0, ended = 0;
bool jud = false;
int result = 10000000;
void bfs() {

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			visited[i][j] = 0;

	que[ended][0] = 1, que[ended++][1] = 1;
	visited[1][1] = 1; //방문햇다고

	

	while (start != ended) {
		int y = que[start][0], x = que[start++][1];
		

		if (y == n && x == m)
		{
			
			jud = true;
			if (result > visited[n][m]) {
				result = visited[n][m];
				break;

			}
		}


		if (arr[y - 1][x] == '0' && (y - 1) > 0 && visited[y - 1][x] == 0)
			que[ended][0] = y - 1, que[ended++][1] = x, visited[y - 1][x] = visited[y][x] + 1;

		if (arr[y + 1][x] == '0' && (y + 1) <= n && visited[y + 1][x] == 0)
			que[ended][0] = y + 1, que[ended++][1] = x, visited[y + 1][x] = visited[y][x] + 1;

		if (arr[y][x - 1] == '0' && (x - 1) > 0 && visited[y][x - 1] == 0)
			que[ended][0] = y, que[ended++][1] = x - 1, visited[y][x - 1] = visited[y][x] + 1;

		if (arr[y][x + 1] == '0' && (x + 1) <= m && visited[y][x + 1] == 0)
			que[ended][0] = y, que[ended++][1] = x + 1, visited[y][x + 1] = visited[y][x] + 1;

	


	}

}



int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i] + 1;

	bfs();
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++) 
			if (arr[i][j] == '1') {
				arr[i][j] = '0';
				bfs();
				arr[i][j] = '1';

			}
		
	if (jud == true)
		cout << result << '\n';
	else
		cout << -1 << '\n';
	return 0;
}