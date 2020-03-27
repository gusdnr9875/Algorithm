#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001] = { 0 };
int arr2[100001] = { 0 };
int n, h;
int result = 200001, result_cnt = 0;


int main() {
	cin >> n >> h;

	for (int i = 0; i < n/2; i++) 
		cin >> arr[i ] >> arr2[i];
		
	sort(arr, arr + (n / 2));
	sort(arr2, arr2 + (n / 2));


	for (int i = 1; i <= h; i++) {

		int val = lower_bound(arr, arr + (n / 2), i ) - arr ;
		val += upper_bound(arr2, arr2 + (n / 2), h-i ) - arr2 ;
		val = n - val;

		if (result == val)
			result_cnt++;
		else if (result > val) { 
			result = val;
			result_cnt = 1;
		}
	}

	cout << result << ' ' << result_cnt << endl;

}