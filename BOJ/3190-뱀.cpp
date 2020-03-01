/*
1. 값 입력받기  ok
2. 현재 방향에 따라 뱀 이동시키기 (이동규칙 3가지는 문제 참조)  ok
	4방향으로 구분, 사과가 있을때와 사과가 없을때로 구분 ok
3. 이때 벽이거나 자기에게 닿으면 종료  ok
4. 방향전환을 해야하는지 확인 ok

*/

#include <iostream>
using namespace std;
typedef struct snaketurn
{
	int x;
	char c;
}snaketurn;

int n, k,l;
int arr[101][101] = { 0, };
int yy, xx; //입력을 위한 

snaketurn turned[100];
int snakeEnd = 0; //  X가 증가하는 순으로 주어지니까 포인터를 만든 것
int sec = 0, currentDirection = 1;

int snake[101][2] = { 0, }; //뱀의 좌표를 저장해둘 공간들  행, 열 순
int snakePointer = 0;

int lasty = 0, lastx = 0;

void modify();
void changedirection();
int main() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> yy >> xx;
		arr[yy][xx] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
		cin >> turned[i].x >> turned[i].c;
	//1
	snake[0][0] = 1, snake[0][1] = 1; //처음에 뱀의 위치를 지정 

	while (1) {
		bool jud = false;
		sec++;
		modify(); //2
		// ------------------3----------------------
		if (snake[0][0]<1 || snake[0][1]<1 || snake[0][0]>n || snake[0][1]>n) //벽에 부딪힐때 
			break;
		for (int i = 1; i <= snakePointer; i++) { //자기 자신한테 부딪히는지 확인 
			if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1]) {
				jud = true;
				break;
			}
		}
		if (jud == true)
			break;

		if (lastx == snake[0][1] && lasty == snake[0][0])
			break;
		//--------------------4------------------
		changedirection(); //4
	}
	cout << sec << endl;
}



void modify() {
	lasty = snake[snakePointer][0], lastx = snake[snakePointer][1];
	if (currentDirection == 1) { //오른쪽 방향 
		if (arr[snake[0][0]][snake[0][1] + 1] == 1) {//이동할 공간에 사과가 있다면 
			arr[snake[0][0]][snake[0][1] + 1] = 0; //0으로 초기화 
			snakePointer++;
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][1] = snake[0][1] + 1; //오른쪽으로 한방향 이동 

		}
		else { //사과가 없을때 
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][1] = snake[0][1] + 1; //오른쪽으로 한방향 이동 
		}
	}




	else if (currentDirection == 2) { //아래방향
		if (arr[snake[0][0] + 1][snake[0][1]] == 1) {//이동할 공간에 사과가 있다면 
			arr[snake[0][0] + 1][snake[0][1]] = 0;
			snakePointer++;
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][0] = snake[0][0] + 1; //아래로 한칸이동
		}
		else { //사과가 없을때 
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][0] = snake[0][0] + 1; //아래로 한칸이동 
		}
	}


	else if (currentDirection == 3) { //왼쪽 방향
		if (arr[snake[0][0]][snake[0][1] - 1] == 1) {//이동할 공간에 사과가 있다면 
			arr[snake[0][0]][snake[0][1] - 1] = 0; //0으로 초기화 
			snakePointer++;
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][1] = snake[0][1] - 1; //오른쪽으로 한방향 이동 
		}
		else { //사과가 없을때 
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][1] = snake[0][1] - 1; //오른쪽으로 한방향 이동 
		}

	}
	else if (currentDirection == 4) {  //위로 이동하는경우 
		if (arr[snake[0][0] - 1][snake[0][1]] == 1) {//이동할 공간에 사과가 있다면 
			arr[snake[0][0] - 1][snake[0][1]] = 0;
			snakePointer++;
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][0] = snake[0][0] - 1; //아래로 한칸이동
		}
		else { //사과가 없을때 
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][0] = snake[0][0] - 1; //아래로 한칸이동 
		}
	}




}


void changedirection() {

	if (turned[snakeEnd].x == sec) {
		if (currentDirection == 1) {
			if (turned[snakeEnd].c == 'D')
				currentDirection = 2;
			else
				currentDirection = 4;
		}
		else if (currentDirection == 2) {
			if (turned[snakeEnd].c == 'D')
				currentDirection = 3;
			else
				currentDirection = 1;
		}
		else if (currentDirection == 3) {
			if (turned[snakeEnd].c == 'D')
				currentDirection = 4;
			else
				currentDirection = 2;
		}
		else if (currentDirection == 4) {
			if (turned[snakeEnd].c == 'D')
				currentDirection = 1;
			else
				currentDirection = 3;
		}

		snakeEnd++;
	}

}