#include <stdio.h>

int n=0, m=0,mini=1000001;

char arr[103][103];
int visited[103][103] = { 0 };

int que[100001][2] = { 0 };
int  start = 0,end=0;
void bfs(int x,int y ) {
	
	visited[y][x]++;
	que[end][0] = x;
	que[end++][1] = y;
	

	arr[y][x] = '0';
	while (start!=end) {
		int cx = que[start][0];
		int cy = que[start++][1];
		
		
		if (arr[cy][cx + 1] == '1' && (cx+1)>=1&& (cx+1)<=m && cy>=1 && cy<=n) {
			
			que[end][0] = cx + 1, que[end++][1] = cy;
			visited[cy][cx + 1] = visited[cy][cx] + 1;
			arr[cy][cx+1] = '0';
		}
		if (arr[cy][cx - 1] == '1'&& (cx-1) >= 1 && (cx-1) <= m && cy >= 1 && cy <= n) {
			que[end][0] = cx - 1, que[end++][1] = cy;
			visited[cy][cx - 1] = visited[cy][cx] + 1;
			arr[cy][cx - 1] = '0';
		}

		if (arr[cy + 1][cx] == '1'&& cx >= 1 && cx <= m && (cy+1) >= 1 && (cy+1) <= n) {
			que[end][0] = cx , que[end++][1] = cy+1;
			visited[cy + 1][cx] = visited[cy][cx] + 1;
			arr[cy + 1][cx] = '0';
		}
		if (arr[cy - 1][cx] == '1'&& cx >= 1 && cx <= m && (cy-1) >= 1 && (cy-1) <= n) {
			que[end][0] = cx, que[end++][1] = cy - 1;
			visited[cy - 1][cx] = visited[cy][cx] + 1;
			arr[cy - 1][cx] = '0';
		}

		
	}

	

	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", arr[i]+1);

	bfs(1, 1);
	printf("%d\n", visited[n][m]);
	
}