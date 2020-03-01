#include <iostream>
using namespace std;
typedef struct a {
	int y;
	int x;
	bool select = false;
}b;
int arr[52][52] = { 0 };
int arr2[52][52] = { 0 };
b birus[10];
int n, m,b_size=0;
int result = 1000000000;

void bfs() {
	int k = 0;
	int que[2501][2] = { 0 };  // 큐를 담당
	int start = 0, ended = 0; // 스타트 엔드값
	int cnt = 0;
	for (int i = 0; i < b_size; i++) {
		if (birus[i].select == true)
			que[ended][0] = birus[i].y, que[ended++][1] = birus[i].x; //큐에 넣고
		else
			arr[birus[i].y][birus[i].x] = 0;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr2[i][j] = arr[i][j];

	while (k++<1500) {
		bool jud = false;
		int ede = ended;
		cnt++;
		while (start < ede) {

			int y = que[start][0];
			int x = que[start++][1]; //숫자를 하나 뺀다.


			if ((x - 1) >= 1 && arr2[y][x-1]==0) {
				arr2[y][x - 1] = -1;
				que[ended][0] = y, que[ended++][1] = x - 1;
			}
			if ((x + 1) <= n&& arr2[y][x + 1] == 0) {
				arr2[y][x + 1] = -1;
				que[ended][0] = y, que[ended++][1] = x + 1;
			}
			if ((y - 1) >= 1 && arr2[y - 1][x] == 0) {
				arr2[y - 1][x] = -1;
				que[ended][0] = y - 1, que[ended++][1] = x;
			}
			if ((y + 1) <= n && arr2[y + 1][x] == 0) {
				arr2[y + 1][x] = -1;
				que[ended][0] = y + 1, que[ended++][1] = x;
			}
		}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (arr2[i][j] == 0) jud = true;
			}
		if (jud == false) {
			if (cnt < result) result = cnt;
		
			break;
		}
	}

	for (int i = 0; i < b_size; i++) 
			arr[birus[i].y][birus[i].x] = 2;
	
}
void dfs(int current, int cnt) {
	if (cnt == m)
		bfs();

	for (int i = current+1; i < b_size; i++) { //비사이즈기준 
		if (birus[i].select == false){
			birus[i].select = true;
			dfs(i, cnt + 1);
			birus[i].select = false;
			
		}
	}


}
int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				birus[b_size].y = i, birus[b_size++].x = j; // 바이러스 를 저장합니다. 
		}
	//dfs를 통해 바이러스를 선정하는과정
	for (int i = 0; i < b_size; i++) {
		birus[i].select = true;
		dfs(i, 1);
		birus[i].select = false;
	}
	if (result != 1000000000)
		cout << result << endl;
	else
		cout << -1 << endl;
}