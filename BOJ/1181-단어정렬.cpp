#include <iostream>
#include <cstdlib>
#include <string>
#include<set>
using namespace std;

int n = 0;
set <string> sorted[51];
set<string>::iterator iter;

int main() {
	string arr;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> arr;
		sorted[arr.size()].insert(arr);
		
	}
	for (int i = 1; i <= 50; i++) {
		for (iter = sorted[i].begin(); iter != sorted[i].end(); iter++)
			cout << *iter << endl;
	}

}