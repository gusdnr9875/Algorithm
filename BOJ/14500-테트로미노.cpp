#include <iostream>
using namespace std;
int n = 0, m = 0;
int arr[501][501] = { 0 };
int result = 0;

void rec1(int x, int y) { //���簢���϶�
	int sum = 0;
	if ((x + 1) <= m && (y + 1) <= n)
		sum = arr[y][x] + arr[y + 1][x] + arr[y][x + 1] + arr[y + 1][x + 1];
	if (result < sum) result = sum;


}
void rec2(int x, int y) { // ����ó�� ���
	int sum = 0;
	if ((x + 3) <= m) //�����϶�
		sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y][x + 3];
	if (result < sum) result = sum;
	sum = 0;
	if ((y + 3) <= n) //�����϶�
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 3][x];
	if (result < sum) result = sum;

}

void rec3(int x, int y) { //�� ������϶� ��Ī�� �Ǵϱ� �����ؾ��� �� 8���� ��츦 ��������� 
	int sum = 0;
	if ((y - 2) >= 1 && (x - 1) >= 1) // �����
		sum = arr[y][x] + arr[y -1][x] + arr[y - 2][x] + arr[y - 2][x - 1];
	if (result < sum) result = sum;

	if ((y - 2) >= 1 && (x + 1) <= m) //
		sum = arr[y][x] + arr[y -1][x] + arr[y - 2][x] + arr[y - 2][x + 1];
	if (result < sum) result = sum;

	//���� �Ϸ� 
	if ((x - 2) >= 1 && (y - 1) >= 1) // L���
		sum = arr[y][x] + arr[y ][x -1] + arr[y][x - 2] + arr[y - 1][x - 2];
	if (result < sum) result = sum;

	if ((x - 2) >= 1 && (y + 1) <= m) //
		sum = arr[y][x] + arr[y][x - 1] + arr[y][x - 2] + arr[y + 1][x - 2];
	if (result < sum) result = sum;
	//���ʿϷ�
	if ((x + 2) <= m && (y - 1) >= 1) // 
		sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y - 1][x + 2];
	if (result < sum) result = sum;

	if ((x + 2) <= m && (y + 1) <= n) // 
		sum = arr[y][x] + arr[y ][x + 1] + arr[y ][x + 2] + arr[y + 1][x + 2];
	if (result < sum) result = sum;
	//�����ʿϷ�
	if ((y + 2) <= n && (x - 1) >= 1) // 
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x - 1];
	if (result < sum) result = sum;

	if ((y + 2) <= n && (x + 1) <= m) //
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x + 1];
	if (result < sum) result = sum;
	//�Ʒ���

}


void rec4(int x, int y) { // 4��° ����� �غ��� �� 8���� �����ؾ߰��� 

	int sum = 0;

	if ((x + 1) <= m && (y + 2) <= n)
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 2][x + 1];
	if (result < sum) result = sum;

	if ((x - 1) >= 1 && (y + 2) <= n)
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y + 2][x - 1];
	if (result < sum) result = sum;

	// �Ʒ��� �������°� �Ϸ� 

	if ((x + 2) <= m && (y - 1) >= 1)
		sum = arr[y][x] + arr[y][x + 1] + arr[y - 1][x + 1] + arr[y - 1][x + 2];
	if (result < sum) result = sum;

	if ((x + 2) <= m && (y + 1) <= n)
		sum = arr[y][x] + arr[y][x + 1] + arr[y + 1][x + 1] + arr[y + 1][x + 2];
	if (result < sum) result = sum;
	//���������� ġ��ģ��  ����

	if ((x - 1) >= 1 && (y - 2) >= 1)
		sum = arr[y][x] + arr[y - 1][x] + arr[y - 1][x - 1] + arr[y - 2][x - 1];
	if (result < sum) result = sum;

	if ((x + 1) <= m && (y - 2) >= 1)
		sum = arr[y][x] + arr[y - 1][x] + arr[y - 1][x + 1] + arr[y - 2][x + 1];
	if (result < sum) result = sum;

	//���� ġ��ģ�� ����

	if ((x - 2) >= 1 && (y - 1) >= 1)
		sum = arr[y][x] + arr[y][x - 1] + arr[y - 1][x - 1] + arr[y - 1][x - 2];
	if (result < sum) result = sum;

	if ((x - 2) >= 1 && (y + 1) <= n)
		sum = arr[y][x] + arr[y][x - 1] + arr[y + 1][x - 1] + arr[y + 1][x - 2];
	if (result < sum) result = sum;
	//�������� ġ��ģ�� 

}

void rec5(int x, int y) { //����� ������ 8�� 

	int sum = 0;

	if ((x + 2) <= m && (y - 1) >= 1)
		sum = arr[y][x] + arr[y][x + 1] + arr[y - 1][x + 1] + arr[y][x + 2];
	if (result < sum) result = sum;

	if ((x + 2) <= m && (y + 1) <= n)
		sum = arr[y][x] + arr[y][x + 1] + arr[y + 1][x + 1] + arr[y][x + 2];
	if (result < sum) result = sum;

	// ������ ���� 

	if ((x - 1) >= 1 && (y - 2) >= 1)
		sum = arr[y][x] + arr[y - 1][x] + arr[y - 1][x - 1] + arr[y - 2][x];
	if (result < sum) result = sum;

	if ((x + 1) <= m && (y - 2) >= 1)
		sum = arr[y][x] + arr[y - 1][x] + arr[y - 1][x + 1] + arr[y - 2][x];
	if (result < sum) result = sum;
	// ���� ����

	if ((x - 2) >= 1 && (y - 1) >= 1)
		sum = arr[y][x] + arr[y][x - 1] + arr[y - 1][x - 1] + arr[y][x - 2];
	if (result < sum) result = sum;

	if ((x - 2) >= 1 && (y + 1) <= n)
		sum = arr[y][x] + arr[y][x - 1] + arr[y + 1][x - 1] + arr[y][x - 2];
	if (result < sum) result = sum;


	//���� ���� 

	if ((x - 1) >= 1 && (y + 2) <= n)
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y + 2][x];
	if (result < sum) result = sum;

	if ((x + 1) <= m && (y + 2) <= n)
		sum = arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 2][x];
	if (result < sum) result = sum;
	//���� ���� 

}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];


	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			rec1(j, i);
			rec2(j, i);
			rec3(j, i);
			rec4(j, i);
			rec5(j, i);
		}

	cout << result << endl;
	return 0;
}