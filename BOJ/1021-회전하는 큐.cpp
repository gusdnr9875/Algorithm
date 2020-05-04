#include <iostream>
#include <deque>
using namespace std;

deque <int> arr;
int n = 0, m = 0;
int cnt = 0;
int arr_m[51];
int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		arr.push_back(i);
	for (int i = 0; i < m; i++)
		cin >> arr_m[i];

	for (int i = 0; i < m; i++) {
		
		int num = arr_m[i];
		int num_index = -1;
		for (int i = 0; i < arr.size(); i++) {
			if (num == arr[i])
				num_index = i;
		}

		// 왼쪽으로 가는게 빠른지 오른쪽으로 가는게 빠른지
		
		//1.왼쪽이 이동하는게 빠를때
		if (num_index <= arr.size() - num_index) {
			for (int i = 0; i < num_index; i++) {
				int val = arr.front();
				arr.push_back(val);
				arr.pop_front();
				cnt++;
			}
			arr.pop_front();
		}
		// 2. 오른쪽으로 이동하는게 빠를때 
		else {
			for (int i = arr.size() - 1; i >= num_index; i--) {
				int val = arr.back();
				arr.push_front(val);
				arr.pop_back();
				cnt++;
			}
			arr.pop_front();
		}
	}
	cout << cnt << '\n';
}