#include <iostream>
using namespace std;
typedef struct zi {
	int x, y;
}zapo;
zapo B;
zapo R;

char arr[11][11];
bool visited[11][11];

void bfs() { //�Ź� ������ �ִ��������� Ȯ�� �ϸ� ���� �� ������ ��ġ�� ���� �ൿ�� ���ݾ� �޶����°� Ư¡ 


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