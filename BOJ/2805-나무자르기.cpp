#include <iostream>
using namespace std;
int n = 0;
int arr[1000001] = { 0 };
long long m = 0, result = 0;
long long maxed = 0;
long long buttom = 0, top = 2000000000, mid = 1000000000;
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; //����
	}
	
	while (buttom <= top)
	{
		mid = (top + buttom) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++)
			if (mid < arr[i])
				sum += arr[i] - mid;
		if (sum >= m&& maxed < mid) //�ƽ��� �ִ���̸� �ǹ��մϴ�. ����? 
			maxed = mid;

		

		else if (sum >= m) {//���߶������?
			buttom = mid + 1;
			continue;
		}
		else if (sum < m) {//�� �߶������?
			top = mid - 1;
			continue;
		}
	}


	cout << maxed << '\n';


}