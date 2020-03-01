// �� �� �� �� 1 2 3 4
/*
 1. �̵��� �� �ִ� �������� Ȯ���ϰ� �Ұ����ϸ� continue�� �̵��������� ������  O
 2. ��ǥ���� ��, �̵��� �� ������ �ֻ��� ����ŷ O
 3. �ٴ��� 0�̸� �ٴڿ� �ֻ����� �ش���� �ֱ� O
 4. �ٴ��� 0�� �ƴϸ� ĭ�� ���� �ִ� ���� �ֻ����� �ٴڸ����� ����Ǹ�, ĭ�� ���� �ִ� ���� 0�� �ȴ�. O
 5. ���� dice[1]�� ����Ѵ�. O
*/
#include <iostream>
using namespace std;

int n, m, x, y, k;
int arr[21][21] = { 0 };
int karr[1000] = { 0 };
int dice[7] = { 0, }; // �ε��� ������� ���� ��Ÿ���°�  6��°�� �׻� �Ʒ��� �Ǵ� �����ΰ��� 

void verifydice(int direction) {
	int temp = 0;

	if (direction == 1) {
		temp = dice[6];
		dice[6] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[4];
		dice[4] = temp;
		// 2�� 5�� ������ ����
	}
	else if (direction == 2) {
		temp = dice[6];
		dice[6] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[3];
		dice[3] = temp;
		// 2�� 5�� ������ ����
	}
	else if (direction == 3) {
		temp = dice[6];
		dice[6] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[2];
		dice[2] = temp;
		// 3�� 4�� ������ ����
	}
	else if (direction == 4) {
		temp = dice[6];
		dice[6] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[5];
		dice[5] = temp;
		// 3�� 4�� ������ ����
	}

}

int main() {

	cin >> n >> m >> x >> y >> k; //�Է�1  (x,y)

	for (int i = 0; i < n; i++) //�Է�2
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < k; i++) //�Է�3
		cin >> karr[i];


	for (int s = 0; s < k; s++) { // k�� ��ŭ Ƚ��

		if (karr[s] == 1) { // �������� �̵��Ҷ� 
			if ((y + 1) >= m)
				continue;
			y++;
			verifydice(1);

		}
		else if (karr[s] == 2) { //�������� �̵��Ҷ� 
			if ((y - 1) < 0)
				continue;
			y--;
			verifydice(2);

		}
		else if (karr[s] == 4) { //�������� �̵��Ҷ� 
			if ((x + 1) >= n)
				continue;
			x++;
			verifydice(3);

		}
		else if (karr[s] == 3) { //�������� �̵��Ҷ� 
			if ((x - 1) < 0)
				continue;
			x--;
			verifydice(4);
		}

		//3,4���� ����� ���� 
		if (arr[x][y] == 0)
			arr[x][y] = dice[6];
		else {
			dice[6] = arr[x][y];
			arr[x][y] = 0;
		}
		//5��
		cout << dice[1] << endl;
	}


}