// 동 서 남 북 1 2 3 4
/*
 1. 이동할 수 있는 구간인지 확인하고 불가능하면 continue로 이동하지말구 나가기  O
 2. 좌표변경 후, 이동할 수 있으면 주사위 쉐이킹 O
 3. 바닥이 0이면 바닥에 주사위의 해당수를 넣기 O
 4. 바닥이 0이 아니면 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다. O
 5. 윗면 dice[1]을 출력한다. O
*/
#include <iostream>
using namespace std;

int n, m, x, y, k;
int arr[21][21] = { 0 };
int karr[1000] = { 0 };
int dice[7] = { 0, }; // 인덱스 순서대로 값을 나타내는것  6번째가 항상 아래가 되는 구조인거지 

void verifydice(int direction) {
	int temp = 0;

	if (direction == 1) {
		temp = dice[6];
		dice[6] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[4];
		dice[4] = temp;
		// 2랑 5는 동일한 구조
	}
	else if (direction == 2) {
		temp = dice[6];
		dice[6] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[3];
		dice[3] = temp;
		// 2랑 5는 동일한 구조
	}
	else if (direction == 3) {
		temp = dice[6];
		dice[6] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[2];
		dice[2] = temp;
		// 3랑 4는 동일한 구조
	}
	else if (direction == 4) {
		temp = dice[6];
		dice[6] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[5];
		dice[5] = temp;
		// 3랑 4는 동일한 구조
	}

}

int main() {

	cin >> n >> m >> x >> y >> k; //입력1  (x,y)

	for (int i = 0; i < n; i++) //입력2
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < k; i++) //입력3
		cin >> karr[i];


	for (int s = 0; s < k; s++) { // k번 만큼 횟수

		if (karr[s] == 1) { // 동쪽으로 이동할때 
			if ((y + 1) >= m)
				continue;
			y++;
			verifydice(1);

		}
		else if (karr[s] == 2) { //서쪽으로 이동할때 
			if ((y - 1) < 0)
				continue;
			y--;
			verifydice(2);

		}
		else if (karr[s] == 4) { //남쪽으로 이동할때 
			if ((x + 1) >= n)
				continue;
			x++;
			verifydice(3);

		}
		else if (karr[s] == 3) { //북쪽으로 이동할때 
			if ((x - 1) < 0)
				continue;
			x--;
			verifydice(4);
		}

		//3,4번의 기능을 구현 
		if (arr[x][y] == 0)
			arr[x][y] = dice[6];
		else {
			dice[6] = arr[x][y];
			arr[x][y] = 0;
		}
		//5번
		cout << dice[1] << endl;
	}


}