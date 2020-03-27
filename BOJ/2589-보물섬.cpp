#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int height, width;

string arr[51];
int visited[51][51];
int que[2501][2];
int started,ended;
int de_x[4] = { 1, 0, 0,-1 };
int de_y[4] = { 0, 1,-1, 0 };
int result = 0;

void bfs(int a, int b) {
	started = 0, ended = 0;
	que[ended][0] = a;
	que[ended][1] = b;
	ended++;

	while (started != ended) {
		int y = que[started][0];
		int x = que[started++][1];
		
		for (int i = 0; i < 4; i++) {
			if ((y + de_y[i])>=0 && (y + de_y[i])<height && (x + de_x[i])>=0 && (x + de_x[i])<width)
				if (arr[y + de_y[i]][x + de_x[i]] == 'L' && !visited[y + de_y[i]][x + de_x[i]] && (a!= y + de_y[i] || b != x + de_x[i]))
				{
					visited[y + de_y[i]][x + de_x[i]] = visited[y][x] + 1;
					que[ended][0] = y + de_y[i];
					que[ended++][1] = x + de_x[i];
					
				}

		}
		
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (arr[i][j] == 'W') continue;
			if (result < visited[i][j] ) result = visited[i][j];
		}
	}


}
int main() {

	cin >> height >> width;
	for (int i = 0; i < height;i++)
		cin >> arr[i];

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (arr[i][j] == 'W') continue;
			memset(visited, 0, sizeof(visited));
			
			bfs(i,j);


		}
	}

	cout << result << endl;
}