#include <iostream>
using namespace std;
/*
1���� ȸ���� ������ 4���� ���  -> �Ʒ� �����ʸ� ���ָ� �� 
3�� ���ʹ� ȸ���̳� ��Ī�� ��Ű�°� �����ϱ⿡ �� 8���� 
*/
int n = 0, m = 0, result = 0;
int arr[501][501] = { 0 };

void num1() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= m - 4; j++)
			if ((arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3]) > result) result = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3]);

	for (int i = 0; i < m; i++)
		for (int j = 0; j <= n - 4; j++)
			if ((arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 3][i]) > result) result = (arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 3][i]);
}


void num2() {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			if ((arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]) > result) result = (arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]);

}

void num3() {
	/*
	// �⺻ ���
	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j <= n - 3; j++)
			if ((arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 2][i + 1]) > result) result = (arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 2][i + 1]);
	// �⺻ ��Ī
	for (int i = 1; i < m; i++)
		for (int j = 0; j <= n - 3; j++)
			if ((arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 2][i - 1]) > result) result = (arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 2][i - 1]);
	//���� 90��
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= m - 3; j++)
			if ((arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2]) > result) result = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2]);
	//���� 90�� ��Ī
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j <= m - 3; j++)
			if ((arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]) > result) result = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]);
	// ���� 180��*/
	for (int i = 2; i < n; i++)
		for (int j = 1; j < m; j++)
			if ((arr[i][j] + arr[i - 1][j] + arr[i - 2][j] + arr[i - 2][j - 1]) > result) result = (arr[i][j] + arr[i - 1][j] + arr[i - 2][j] + arr[i - 2][j - 1]);
	// ���� 180�� ��Ī 

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
	//num1();
	
	//num2();
	cout<< result << endl;
	

}