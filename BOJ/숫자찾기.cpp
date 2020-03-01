#include <iostream>
using namespace std;
int s = 0, p = 0, k = 0;
int arr[4] = { 0 };
void select(int cnt,int sum,int current) {
	if (cnt == k&& (sum) == s)
	{
		for (int i = 0; i < k; i++)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}
	for (int i = current; i + sum <= p; i++) {
			arr[cnt] = i;
			select(cnt + 1, sum + i, i);
			return;
		
	}
}

int main() {
	cin >> s >> p >> k;
	for (int i = 1; i <= s; i++) {
		arr[0] = i;
		select(1, i, i);
	}
}