#include <iostream>
using namespace std;

int n = 0, k = 0;
int arr[100001] = { 0 }; //
int arr_cur = 0,arr2_cur=0;
char arr2[100001] = { 0 }; //
int result = 0;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;

		if (arr[arr_cur] == k) {
			arr_cur--;
			arr2[arr2_cur++] = '-';
		}
		else if (arr[arr_cur] < k) {
			for (int i = 1; i < k; i++) {
				arr[++arr_cur] = i;
				arr2[arr2_cur++] = '+';
			}
				
		}
		else {
			cout << "NO" << '\n';
			return 0;
		}

		
	}
	for (int i = 0; i < arr2_cur; i++)
	{
		cout << arr2[i] << '\n';
	}

	
}