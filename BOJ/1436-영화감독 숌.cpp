#include <iostream>
using namespace std;
int n = 0;
int arr_index = 0;
int val[15]; //�ڸ������� ������ �迭 

int main() {
	cin >> n;

	for (int i = 666; arr_index != n; i++) {
		int num = i;
		int num_size = 0;
		bool jud = false;

		while (num) { // 10�̸� 2�ڸ��� �̷��� 
			val[num_size] = num % 10;
			num /= 10;
			num_size++;	
		}
		num = i; // �ٽ� num�� i 
		for (int j = 0; j <= num_size - 3; j++) {
			if (val[j] == 6 && val[j + 1] == 6 && val[j + 2] == 6) {
				jud = true;
				break;
			}
		}
		if (jud == true)
			arr_index++;
		if (arr_index == n) {
			cout << i << '\n';
			return 0;
		}
	}
}