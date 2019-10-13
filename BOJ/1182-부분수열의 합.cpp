#include <iostream>

#include <vector>
using namespace std;

int n = 0, s = 0;
int arr[1000001] = { 0 };
int cnt = 0;
void dfs(int index,int sum,int lenth) {
	if (index == n) {
		if(sum==s&&lenth!=0)
			cnt++;
		return;
	}

	
	dfs(index + 1, sum, lenth);
	dfs(index + 1, sum + arr[index+1], lenth+1);
	
	

	return;
}

int main() {


	cin >> n >> s;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dfs(1,0,0);
	dfs(1, arr[1], 1);
	cout << cnt << endl;

}

