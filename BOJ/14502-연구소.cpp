#include <iostream>
using namespace std;
int n = 0, m = 0;
int start = 0, ended = 0;

int arr[9][9] = { 0 };
int copies[9][9] = { 0 };
int que[81][2] = { 0 };
int maxed = 0;

void cp() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			copies[i][j] = arr[i][j];
}
void bfs() {
	cp();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			if (copies[i][j] == 2)
			{
				start = 0, ended = 0;
				que[ended][0] = j, que[ended++][1] = i;
				while (start != ended) {
					int x = que[start][0], y = que[start++][1];
					if (copies[y][x + 1] == 0 && (x+1)>0&&(x+1)<=m&&y>0&&y<=n) {
						que[ended][0] = x + 1, que[ended++][1] = y;
						copies[y][x + 1] = 3;
					}
					if (copies[y][x - 1] == 0 && (x - 1)>0 && (x - 1) <= m&&y>0 && y <= n) {
						que[ended][0] = x - 1, que[ended++][1] = y;
						copies[y][x - 1] = 3;
					}
					if (copies[y + 1][x] == 0 && (y + 1)>0 && (y + 1) <= n&&x>0 && x <= m) {
						que[ended][0] = x, que[ended++][1] = y + 1;
						copies[y + 1][x] = 3;
					}
					if (copies[y - 1][x] == 0 && (y - 1)>0 && (y - 1) <= n&&x>0 && x <= m) {
						que[ended][0] = x, que[ended++][1] = y - 1;
						copies[y - 1][x] = 3;
					}
				}
			}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (copies[i][j] == 0)
				cnt++;
	if (maxed < cnt)
		maxed = cnt;
		
}


void count(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (arr[i][j] == 0)
			{
				arr[i][j] = 1;
				count(cnt+1);
				arr[i][j] = 0;
			}
	return;
}


int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
		
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++)
			if (arr[i][j] == 0)
			{
				arr[i][j] = 1;
				count(1);
				arr[i][j] = 0;
			}
		
	cout << maxed << '\n';

}