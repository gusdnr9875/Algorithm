#include <iostream>
using namespace std;

int arr[16][16] = { 0 };
int mini = 987654321;
int dat[16] = { 0 };
int n = 0;

void dfs(int start, int current, int sum, int count) {
	if (start == current&&count == n) { //���� �������̶� ���������̶� ���� ī��Ʈ���� (��ȸ) �־��� n�� ������ 
		if (mini > sum) {  //min������ sum�� ������ 
			mini = sum;
		}
		return;
	}

	for (int i = 1; i <= n; i++) { //�� ���� ��ȸ�� �����մϴ�. 
		if (arr[current][i] == 0) continue; //���� ������ ���ٸ� ���� �����.

		if (dat[current] != 1) {

			dat[current] = 1; //���� ������ �����Դٰ� ǥ�����ֱ� 
			sum += arr[current][i]; //�� ������ ����ġ���� �����ְ�!

			if (sum <= mini)
				dfs(start, i, sum, count + 1);  //���� ��ȸ�Ұ����� ���� 

												//�湮�� ��ϰ� �� �ʱ�ȭ
			dat[current] = 0;
			sum -= arr[current][i];
		}

	}

}


int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	/*
	for (int i = 1; i <= n; i++)
	dfs(i, i, 0, 0);
	*/
	dfs(1, 1, 0, 0);

	cout << mini << endl;
}