#include <iostream>
using namespace std;
int n = 0, m = 0, v = 0;
int arr[1001][1001] = { 0 };
int visited[1001] = { 0 }; //방문여부를 판단한 배열입니다. 
int x, y;

int queue[10001] = { 0 };
int start = 0, ended = 0;

void dfs(int current) {
	visited[current] = 1;
	cout << current << ' ';
	
	for (int i = 1; i <= 1000; i++)
		if (arr[current][i] == 1 && visited[i] == 0) 
			dfs(i);

}

void bfs() {

	int cnt = 0;
	for (int i = 1; i <= 1000; i++)
		visited[i] = 0;

	queue[ended++] = v;
	visited[v] = 1;

	while (start < ended) {
		
		int num = queue[start++]; // 스타트값을 하나 가져온다.	
		cout << num << ' ';
		
		for (int i = 1; i <= 1000; i++)
			if (arr[num][i] == 1 && visited[i] == 0) {
				queue[ended++] = i;
				visited[i] = 1;
			}
	}

}
int main() {

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> y >> x;
		arr[y][x] = 1;
		arr[x][y] = 1;
	}
	dfs(v);
	cout << endl;
	bfs();
	cout << endl;
}