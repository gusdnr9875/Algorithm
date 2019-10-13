/* 이름:박현욱 */
#include <iostream>
using namespace std;
int arr[10] = { 0 };

int main() {
	int n = 0, m = 0, input = 0;
	int cnt = 0;
	int cnt2 = 500001;

	cin >> n >> m;
	cnt = n - 100; //번호를 안옮기고  + - 로 이동하는 경우의 횟 수 
	if (cnt < 0)
		cnt = (-1 * cnt);

	for (int i = 0; i < m; i++) {
		cin >> input;
		arr[input] = 1; // 안눌리는 번호는 1로 표기됩니다. 
	}

	
	
	for (int i = n;i>=0; i--) {
		int copy = i,k=0;
		bool jud = true;
		while (copy) {
			
			if (arr[copy % 10] == 1) {
				jud = false;
				break;
			}
			
			copy = copy / 10;
			k++;
		}
		if (i == 0 && arr[0] == 0) {
			k++;
		}
		else if (i == 0 && arr[0] == 1)
			jud = false;

		if (jud == true) {
			
			cnt2 = k + (n - i);
			break;
		}
	}

	for (int i = n;(i-n) < cnt2 ; i++) {
		int copy = i, k = 0;
		bool jud = true;
		while (copy) {
			if (arr[copy % 10] == 1) {
				jud = false;
				break;
			}
		
			copy = copy / 10;
			k++;
		}
		if (i == 0 && arr[0] == 0) {
			k++;
		}
		else if (i == 0 && arr[0] == 1)
			jud = false;

		if (jud == true) {
			if (cnt2 > (k + (i - n)))
				cnt2 = k + (i-n);
				break;
		}
	}
	
	if (cnt2 > cnt)
		cout << cnt << '\n';
	else
		cout << cnt2 << '\n';

	
}