#include <iostream>
using namespace std;
int a = 0, b = 0;

int main() {
	char arr[258];

	cin.getline(arr, 255);
	for (int i = 0; arr[i]; i++)
		if (arr[i] == ':' && arr[i + 1] == '-')
			if (arr[i + 2] == ')')
				a++;
			else if(arr[i + 2] == '(')
				b++;

	if (a == 0 && b == 0)
		cout << "none" << endl;
	else if(a==b)
		cout << "unsure" << endl;
	else if(a>b)
		cout << "happy" << endl;
	else if(a<b)
		cout << "sad" << endl;




}