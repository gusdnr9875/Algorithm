#include <iostream>
using namespace std;
struct node {
	int left, right;
};

node arr[200001];

int main() {
	int n; long long k;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i].left >> arr[i].right;

	cin >> k;

	int pos = 1; //��Ʈ ��忡�� ����
	while (1) {
		//1
		if (arr[pos].left == -1 && arr[pos].right == -1) break;
		//2
		else if (arr[pos].left == -1) pos = arr[pos].right; //���ʳ�尡 ���� -> ���������� �̵�
		else if (arr[pos].right == -1) pos = arr[pos].left; //�����ʳ�尡 ���� -> �������� �̵�
															//3
		else if (k % 2) {//1)���� -> Ȧ���� �������� ����.
			pos = arr[pos].left, k = k / 2 + 1;
		}
		else { //2)���� -> ¦���� ���������� ����.
			pos = arr[pos].right, k /= 2;
		}
	}
	cout << pos << endl;

	return 0;
}