#include <iostream>
using namespace std;
int n = 0;
int arr_index = 0;
int val[15]; //자리수들을 저장할 배열 

int main() {
	cin >> n;

	for (int i = 666; arr_index != n; i++) {
		int num = i;
		int num_size = 0;
		bool jud = false;

		while (num) { // 10이면 2자리수 이런식 
			val[num_size] = num % 10;
			num /= 10;
			num_size++;	
		}
		num = i; // 다시 num은 i 
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