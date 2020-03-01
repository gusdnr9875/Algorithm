#include <iostream>
#include <string>
using namespace std;
string arr;

int main() {
	cin >> arr;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == 'C' || arr[i] == 'A' || arr[i] == 'M' || arr[i] == 'B' || arr[i] == 'R' || arr[i] == 'I' || arr[i] == 'D' || arr[i] == 'G' || arr[i] == 'E'){
			arr.erase(i, 1);
		i--;
		}
	}
	if (arr.size() == 0)
		cout << ' ' << endl;
	else
		cout << arr << endl;
}