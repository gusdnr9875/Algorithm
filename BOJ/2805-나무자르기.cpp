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
		cin >> arr[i]; //저장
	}
	
	while (buttom <= top)
	{
		mid = (top + buttom) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++)
			if (mid < arr[i])
				sum += arr[i] - mid;
		if (sum >= m&& maxed < mid) //맥스는 최대높이를 의미합니다. ㅇㅋ? 
			maxed = mid;

		

		else if (sum >= m) {//더잘라봐야쥬?
			buttom = mid + 1;
			continue;
		}
		else if (sum < m) {//덜 잘라봐야쥬?
			top = mid - 1;
			continue;
		}
	}


	cout << maxed << '\n';


}