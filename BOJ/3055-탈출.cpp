#include <iostream>
using namespace std;
int visited[52][52] = { 0 };
char map[52][52];
int r = 0, c = 0;
int cnt = 0;

int quewater[2510][2];
int start1 = 0, end1 = 0;

int quepos[2510][2];
int start2 = 0, end2 = 0;



int main() {
	cin >> r >> c;

	for (int i = 1; i <= r; i++)
		cin >> map[i]+1;
	
	for (int i = 1; i <= r; i++) //물이 있는 위치를 잡아냄
		for (int j = 1; map[i][j]; j++) {
			if (map[i][j] == '*') quewater[end1][0] = i, quewater[end1++][1] = j;
			if (map[i][j] == 'S') quepos[end2][0] = i, quepos[end2++][1] = j;
		}
	while (1) { //초를 나타냄
		//물이 먼저 퍼져야해
		if (start2 == end2)
			break;
		int waterend = end1;
		
		while (start1 != waterend) {
			int y = quewater[start1][0];
			int x = quewater[start1++][1];

			if (map[y - 1][x] == '.'|| map[y - 1][x] == 'S') quewater[end1][0] = y - 1, quewater[end1++][1] = x,map[y-1][x]='*';
			if (map[y + 1][x] == '.' || map[y + 1][x] == 'S') quewater[end1][0] = y + 1, quewater[end1++][1] = x, map[y + 1][x] = '*';
			if (map[y][x - 1] == '.' || map[y][x - 1] == 'S') quewater[end1][0] = y, quewater[end1++][1] = x - 1, map[y][x - 1] = '*';
			if (map[y][x + 1] == '.' || map[y][x + 1] == 'S') quewater[end1][0] = y, quewater[end1++][1] = x + 1, map[y][x + 1] = '*';


		}
		

		int posend = end2;
		
		while (start2 != posend) {
			int y = quepos[start2][0];
			int x = quepos[start2++][1];
			visited[y][x] = 1;
			if (map[y - 1][x] == 'D'|| map[y + 1][x] == 'D'|| map[y][x-1] == 'D' || map[y ][x+1] == 'D' ) {
				cout << cnt + 1 << endl;
				return 0;
			}
				
			if (map[y - 1][x] == '.'&& visited[y - 1][x] == 0) quepos[end2][0] = y - 1, quepos[end2++][1] = x,visited[y-1][x] = 1;;
			if (map[y + 1][x] == '.'&& visited[y + 1][x] == 0) quepos[end2][0] = y + 1, quepos[end2++][1] = x,visited[y+1][x]=1;
			if (map[y][x - 1] == '.'&& visited[y][x - 1] == 0) quepos[end2][0] = y, quepos[end2++][1] = x - 1, visited[y][x - 1]=1;
			if (map[y][x + 1] == '.'&& visited[y][x + 1] == 0) quepos[end2][0] = y, quepos[end2++][1] = x + 1, visited[y][x + 1]=1;
		}
		cnt++;
	}
	cout << "KAKTUS" << '\n';
}