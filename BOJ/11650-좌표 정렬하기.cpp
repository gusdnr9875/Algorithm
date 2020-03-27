#include <iostream>
#include <algorithm>
using namespace std;
struct info {
	int y;
	int x;
};

bool cmp(info a, info b) {
	if (a.x < b.x)
		return true;
	else if (a.x == b.x)
		if (a.y < b.y)
			return true;
	return false;
}
int n = 0;
info arr[100001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++)
		cout << arr[i].x << ' ' << arr[i].y << endl;
}