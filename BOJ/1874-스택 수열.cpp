#include <iostream>
using namespace std;

int n = 0, k = 0,jud=0,cnt=1;
int *arr = new int[100001]; //
int arr_cur = 0, arr2_cur = 0;
char *arr2 = new char[300000]; //



int main() {
	cin >> n;

	while(n--) {
		cin >> k;

		if (arr[arr_cur] == k&& jud==0) {
			arr_cur--;
			arr2[arr2_cur++] = '-';
		}
		else if (arr[arr_cur] < k&& jud==0) {
			for (cnt; cnt <= k; cnt++) {
				arr[++arr_cur] = cnt;
				arr2[arr2_cur++] = '+';
				
			}
			arr2[arr2_cur++] = '-';
			arr_cur--;
		}
		else {
			jud = 1;
			
		}
	}


	if (jud == 1) {
		cout << "NO" << '\n';
	}
	else {
		for (int i = 0; i < arr2_cur; i++)
			cout <<(char) arr2[i] << '\n';
	}
	return 0;

}