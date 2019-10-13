#include <iostream>
using namespace std;

int n = 0,cnt = 0;
int x, y, d, g;
bool visited[401][401] = { 0 };
int dhistory[20][11] = { 0 };
int dcur[20] = { 0 };

int main() {
	cin >> n;
	
	for(int u=0;u<n;u++) {
		cin >> x >> y >> d >> g; // 좌표값을 입력받습니다. 
		x += 200, y += 200;

		visited[y][x] = 1;
	
		if (d == 0) // 0세대에 선을 그어주는 행동 
			visited[y][x + 1] = 1, x++;
		else if (d == 1)
			visited[y - 1][x] = 1, y--;
		else if (d == 2)
			visited[y][x - 1] = 1, x--;
		else
			visited[y + 1][x] = 1, y++;
		
		dhistory[u][dcur[u]++] = d; // 처음에 디가 어느방향으로 움직였는지 저장합니다. 

		for (int i = 1; i <= g; i++) { // 1세대면 한번 2세대면 2번 ~
			int k = dcur[u];
			for (int j =  k-1; j >= 0; j--) { //1세대면 한번 2세대면 두번  즉 세대수와 라인을 그려주는거는 똑같아 
				//몇세대에서 어떻게 이동했는지 참고해야지 
				if (dhistory[u][j] == 0) visited[y - 1][x] = 1, y--, dhistory[u][dcur[u]++] = 1;    //위로 가야해 
				else if (dhistory[u][j] == 1)visited[y][x - 1] = 1, x--, dhistory[u][dcur[u]++] = 2;
				else if (dhistory[u][j] == 2)visited[y + 1][x] = 1, y++, dhistory[u][dcur[u]++] = 3;   //아래로
				else  visited[y][x + 1] = 1, x++, dhistory[u][dcur[u]++] = 0; //오른쪽으로 가야해 
			}
		}

	}
	for (int i = 0; i < 400; i++)
		for (int j = 0; j < 400; j++)
			if (visited[i][j] == 1 && visited[i + 1][j] == 1 && visited[i][j + 1] == 1 && visited[i + 1][j + 1] == 1)
				cnt++;

	

	cout << cnt << '\n';
}