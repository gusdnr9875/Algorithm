#include <iostream>
using namespace std;
int n = 0;
int arr[12] = { 0 };
int plu[4] = { 0 };
long long mini = 100000000000, maxed = -100000000000;

void dfs(int p,int m, int d,int u,int sum,int len) {
	if(len == n - 1)
	{
		if (maxed < sum) maxed = sum;
		if (mini > sum) mini = sum;
		return;
	}

	if (p > 0) {
		dfs(p - 1, m, d, u, sum + arr[len + 1], len + 1);
	}
	if (m > 0) {
		dfs(p , m-1, d, u, sum - arr[len + 1], len + 1);
	}
	if (d > 0) {
		dfs(p, m , d-1, u, sum * arr[len + 1], len + 1);
	}
	if (u > 0) {
		dfs(p, m, d , u-1, sum / arr[len + 1], len + 1);
	}


	return;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> plu[i];


	dfs(plu[0], plu[1], plu[2], plu[3], arr[0], 0);

	cout << maxed << endl;
	cout << mini << endl;

}