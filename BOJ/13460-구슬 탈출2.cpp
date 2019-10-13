#include <iostream>
using namespace std;
typedef struct zi {
	int x, y;
}zapo;
zapo B;
zapo R;

char arr[11][11];
bool visited[11][11];

void bfs() { //매번 굴릴수 있는지없는지 확인 하며 굴림 두 구슬의 위치에 따라 행동이 조금씩 달라지는게 특징 


}

int main() {
	int n = 0, m = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 'B')
				B.x = j, B.y = i;
			else if (arr[i][j] == 'R')
				R.x = j, R.y = i;

	}

	bfs();



}