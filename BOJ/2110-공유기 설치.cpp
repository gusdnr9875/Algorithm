#include <iostream>
#include <cmath>
using namespace std;
int n = 0;
long long m = 0;
long long mini = 2000000000;
bool jud = false;
int result = 0;
int arr[1000001] = { 0 };
int maxed = 0;

void binarysearch(int current) {
	if (current > 1000000000)
		return;

	long long sum = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] - current > 0)
			sum += arr[i] - current; //잘린 나무들의 합 sum
	
	if (sum - m >= 0 && mini >= sum - m) {
		result = current;
		mini = sum - m;
		
	}
	if (current == 0)
		return;

	if (sum > m&&maxed > current)
		binarysearch(current + current / 2);
	if (sum < m&&current>0) {
		binarysearch(current / 2);
		
	}

	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (maxed < arr[i]) maxed = arr[i];
	}

	binarysearch(maxed);

	cout << result << endl;
	return 0;
}