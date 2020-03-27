#include <iostream>
#include <cstring>
using namespace std;

int n = 0, m = 0;
int arr[5001][2];
int visited[5001];
int result = 1000000000,result_index =-1;
int bfs(int num) {
	int val = 0;
	int que[5000];


	memset(que, 0, 5000);
	memset(visited, 0, 5001);
	int started = 0, ended = 0;

	que[ended++] = num;
	visited[num] = 1;
	while (ended != started) {
		int a = que[started++];

		for (int j = 0; j < m; j++) {
			if (arr[j][0] == a && !visited[arr[j][1]]) {
				que[ended++] = arr[j][1];
				visited[arr[j][1]] = visited[a] + 1;
			}
			else if (arr[j][1] == a && !visited[arr[j][0]]) {
				que[ended++] = arr[j][0];
				visited[arr[j][0]] = visited[a] + 1;
			}
		}

	}

	for (int i = 1; i <= n; i++)
		val += visited[i] - 1;


	return val;
	
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> arr[i][0] >> arr[i][1];


	for (int i = 1; i <= n; i++) { //1~n번까지의 경로를 탐색
		int val = bfs(i);
		if (result > val) result = val, result_index = i;
	}
	cout << result_index << endl;
}