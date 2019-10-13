#include <iostream>
using namespace std;

int arr[1001] = { 0 };


int main() {

	int n, k,j=1;

	cin >> n>> k;
	cout << "<";
	for(int i=1;i<=n;i++) {
		int ss = 0;
		while (1) {
		
			if (arr[j] == 0)
				ss++;


			if (ss == k) {
				arr[j] = 1;
				cout << j;
				
				break;
			}

			if (j >= n)
				j = 1;
			else
				j++;
		}
		if (i != n)
			cout << ", ";

	}
	cout << ">\n";

}