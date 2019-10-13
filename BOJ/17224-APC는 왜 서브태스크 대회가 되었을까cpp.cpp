#include <iostream>
using namespace std;

int n = 0, l = 0, k = 0;
int input1=0,input2=0;
int cnt1 = 0, cnt2 = 0;

int main() {
	cin >> n >> l >> k;
	
	if (k == 0) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> input1 >> input2;
		if (input2 <= l) //ad
			cnt2++;
		else if (input1 <= l)
			cnt1++;

		if (cnt2 >= k)
			break;
	}

	if (cnt2 >= k) 
		cout << 140 * cnt2 << '\n';
	else if (cnt2 + cnt1 <= k) //k보다 적게 했을떄
		cout << cnt2 * 140 + cnt1 * 100 << '\n';
	else  //k보다 많이 했으면 
		cout << cnt2 * 140 + (k - cnt2) * 100 << '\n';




}