#include <iostream>
using namespace std;
char arr[6];

int main() {
	
	while (1) {
		int cnt = 0;
		bool jud = 0;
		cin >> arr;

		if (arr[0] == '0')
			break;

		for (int i = 0; arr[i]; i++)
			cnt++;
		for(int i=0;i<cnt/2;i++)
			if (arr[i] != arr[cnt - i-1]) {
				cout << "no\n";
				jud = 1;
				break;
			}
		if(jud==0)
			cout << "yes\n";

	}

}