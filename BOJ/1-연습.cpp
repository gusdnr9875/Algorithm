
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <functional>
using namespace std;

int main(void) {

	//int n;
	//cin >> n;
	//string str = toString(n);

	string str;
	cin >> str;
	int len = str.length();
	int* arr = new int[len];

	for (int i = 0; i < len; i++) {
		char c = (char)str.at(i);
		arr[i] = atoi(c);
	}

	sort(arr, arr + len, greater<int>());

	for (int i = 0; i < len; i++) {
		cout << arr[i];
	}

	delete[] arr;
	return 0;
}