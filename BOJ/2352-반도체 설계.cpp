#include <iostream>
#include <algorithm>
using namespace std;

int n = 0,len=1;
int arr[40001] ;
int arr2[40001] = { 0 };


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	arr2[len] = arr[1]; //초기값 설정
	
	for (int i = 2; i <= n; i++) {
		if (arr2[len] < arr[i]) {
			arr2[++len] = arr[i];
		}
		else {
			int val = lower_bound(arr2 + 1, arr2 + len + 1, arr[i]) - arr2;
			arr2[val] = arr[i];
		
		}
		
	}
	
	cout << len << endl;
}