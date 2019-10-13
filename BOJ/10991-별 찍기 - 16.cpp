#include <iostream>
using namespace std;

int n = 0;


int main() {
	cin >> n;


	for (int i = 0; i < n; i++){ //줄
		for (int j = 0; j < n - i-1; j++) //앞에 공백
			cout << " ";
		for (int j = 0; j <= i; j++)
			cout << "* ";
		cout << '\n';
		
	}
}