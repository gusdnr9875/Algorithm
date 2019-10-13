#include <iostream>
using namespace std;

int t = 0;
int a = 0, b = 0;
int sum = 0;
int main() {
	//파이썬으로 함 
	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		sum = a + b;
		cout << "Case " << i << ": " << sum << endl;
	}
}