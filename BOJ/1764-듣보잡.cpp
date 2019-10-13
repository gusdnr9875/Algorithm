#include <iostream>
#include <string>
#include <algorithm>
#include<set>
using namespace std;

int n, m;

int main() {
	set<string> arr_n;
	set<string> arr_m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		arr_n.insert(a);
	}
	
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		if(arr_n.find(a)!= arr_n.end())
			arr_m.insert(a);
	}
	//sort(arr_m.begin(),arr_m.end());
	cout << arr_m.size() << endl;
	
	for (string i : arr_m) {
		cout << i << endl;
	}

		
}