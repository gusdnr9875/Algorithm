#include <iostream>
using namespace std;

char a[51];
char b[51];
int acnt, bcnt;
int minn = 1000000000;

int main() {
	
	cin >> a >> b;
	for (acnt = 0; a[acnt]; acnt++) {}
	for (bcnt = 0; b[bcnt]; bcnt++) {}

	for (int i = 0; i < bcnt - acnt + 1; i++) {
		int comp = 0;
		for (int j = i, k = 0; a[k]; j++, k++) {
			if (b[j] != a[k])
				comp++;
		}
		if (minn > comp)
			minn = comp;
	}

	if (minn == 1000000000)
		cout << 0 << endl;
	else
		cout << minn << endl;



}