/*
1. �� �Է¹ޱ�  ok
2. ���� ���⿡ ���� �� �̵���Ű�� (�̵���Ģ 3������ ���� ����)  ok
	4�������� ����, ����� �������� ����� �������� ���� ok
3. �̶� ���̰ų� �ڱ⿡�� ������ ����  ok
4. ������ȯ�� �ؾ��ϴ��� Ȯ�� ok

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
int yy, xx; //�Է��� ���� 

snaketurn turned[100];
int snakeEnd = 0; //  X�� �����ϴ� ������ �־����ϱ� �����͸� ���� ��
int sec = 0, currentDirection = 1;

int snake[101][2] = { 0, }; //���� ��ǥ�� �����ص� ������  ��, �� ��
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
	snake[0][0] = 1, snake[0][1] = 1; //ó���� ���� ��ġ�� ���� 

	while (1) {
		bool jud = false;
		sec++;
		modify(); //2
		// ------------------3----------------------
		if (snake[0][0]<1 || snake[0][1]<1 || snake[0][0]>n || snake[0][1]>n) //���� �ε����� 
			break;
		for (int i = 1; i <= snakePointer; i++) { //�ڱ� �ڽ����� �ε������� Ȯ�� 
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
	if (currentDirection == 1) { //������ ���� 
		if (arr[snake[0][0]][snake[0][1] + 1] == 1) {//�̵��� ������ ����� �ִٸ� 
			arr[snake[0][0]][snake[0][1] + 1] = 0; //0���� �ʱ�ȭ 
			snakePointer++;
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][1] = snake[0][1] + 1; //���������� �ѹ��� �̵� 

		}
		else { //����� ������ 
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][1] = snake[0][1] + 1; //���������� �ѹ��� �̵� 
		}
	}




	else if (currentDirection == 2) { //�Ʒ�����
		if (arr[snake[0][0] + 1][snake[0][1]] == 1) {//�̵��� ������ ����� �ִٸ� 
			arr[snake[0][0] + 1][snake[0][1]] = 0;
			snakePointer++;
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][0] = snake[0][0] + 1; //�Ʒ��� ��ĭ�̵�
		}
		else { //����� ������ 
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][0] = snake[0][0] + 1; //�Ʒ��� ��ĭ�̵� 
		}
	}


	else if (currentDirection == 3) { //���� ����
		if (arr[snake[0][0]][snake[0][1] - 1] == 1) {//�̵��� ������ ����� �ִٸ� 
			arr[snake[0][0]][snake[0][1] - 1] = 0; //0���� �ʱ�ȭ 
			snakePointer++;
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][1] = snake[0][1] - 1; //���������� �ѹ��� �̵� 
		}
		else { //����� ������ 
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][1] = snake[0][1] - 1; //���������� �ѹ��� �̵� 
		}

	}
	else if (currentDirection == 4) {  //���� �̵��ϴ°�� 
		if (arr[snake[0][0] - 1][snake[0][1]] == 1) {//�̵��� ������ ����� �ִٸ� 
			arr[snake[0][0] - 1][snake[0][1]] = 0;
			snakePointer++;
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][0] = snake[0][0] - 1; //�Ʒ��� ��ĭ�̵�
		}
		else { //����� ������ 
			for (int i = snakePointer; i > 0; i--) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
			snake[0][0] = snake[0][0] - 1; //�Ʒ��� ��ĭ�̵� 
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