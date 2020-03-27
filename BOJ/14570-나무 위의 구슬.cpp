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

	int pos = 1; //루트 노드에서 시작
	while (1) {
		//1
		if (arr[pos].left == -1 && arr[pos].right == -1) break;
		//2
		else if (arr[pos].left == -1) pos = arr[pos].right; //왼쪽노드가 없음 -> 오른쪽으로 이동
		else if (arr[pos].right == -1) pos = arr[pos].left; //오른쪽노드가 없음 -> 왼쪽으로 이동
															//3
		else if (k % 2) {//1)조건 -> 홀수면 왼쪽으로 간다.
			pos = arr[pos].left, k = k / 2 + 1;
		}
		else { //2)조건 -> 짝수면 오른쪽으로 간다.
			pos = arr[pos].right, k /= 2;
		}
	}
	cout << pos << endl;

	return 0;
}