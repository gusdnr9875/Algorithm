#include <iostream>
#include <string>
using namespace std;
string arr;
int main() {
	int cnt = 0;
	cin >> arr;
	for (int i = 0; i < arr.size(); i++)
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			cnt++;
	cout << cnt << endl;
}