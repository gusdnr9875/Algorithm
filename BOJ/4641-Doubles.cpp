#include <iostream>
using namespace std;
int arr[15] = { 0 };
bool jud = false;

int main() {
	while (1) {
		jud = false;
		int cnt = 0,i=0;
		for (i = 0;;i++) {
			cin >> arr[i];
			if (i == 0 && arr[i] == -1) {
				jud = true;
				break;
			}
			if (arr[i] == 0) {
				break;
			}
		}

		if (jud == true)
			break;

	

		for (int j = i-1; j >= 0; j--) {
			for (int k = i-1; k >= 0; k--) {
				if (arr[k] * 2 == arr[j]) {
					cnt++;
					break;
		
				}

			}
			
		}
		

		cout << cnt << '\n';
	}


}