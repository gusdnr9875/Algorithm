#include <iostream>
#include <string>
using namespace std;

string arr;
int cnt = 0;
int main() {
	getline(cin,arr);

	for (int i = 0; i < arr.size(); i++)
		if (arr[i] == ' ')
			cnt++;
	if (arr[0] == ' ')
		cnt--;
	if (arr[arr.size() - 1] == ' ')
		cnt--;
	cnt++;
	cout << cnt << endl;

}