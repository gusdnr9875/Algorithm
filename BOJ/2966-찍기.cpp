#include <iostream>
using namespace std;

char a[3] = { 'A','B','C' };
char b[4] = { 'B','A','B','C' };
char c[6] = { 'C','C','A','A','B','B' };
char arr[101];
int cnt[3] = { 0 };

int n = 0, result = 0;

int main() {
	cin >> n;
	cin >> arr;

	for (int i = 0; i < n; i++) {
		if (a[i % 3] == arr[i]) cnt[0]++;
		if (b[i % 4] == arr[i]) cnt[1]++;
		if (c[i % 6] == arr[i]) cnt[2]++;
	}
	for (int i = 0; i < 3; i++)
		if (result < cnt[i]) result = cnt[i];
	cout << result << endl;
	if (cnt[0] == result) cout << "Adrian" << endl;
	if (cnt[1] == result) cout << "Bruno" << endl;
	if (cnt[2] == result) cout << "Goran" << endl;
}