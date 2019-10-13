#include <iostream>
using namespace std;
int n = 0,input;
bool arr[200000];
int a1 = 0, a2 = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input > 0) arr[i] = 1;
		else arr[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			if (arr[j] == 0) sum--;
			
			if (sum % 2 == 0) a2++;
			else a1++;
		}
	}
	cout << a1 << ' ' << a2 << '\n';
}