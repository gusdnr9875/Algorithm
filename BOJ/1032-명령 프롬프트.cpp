#include <iostream>
#include <string>
using namespace std;

int n = 0;
string arr[50];
string result; 

int main() {
		
	int len = 0,len_index=-1;
	// input 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i].size() > len) len = arr[i].size(), len_index = i;
	}

	for (int i = 0; i < len; i++) {
		char word = arr[len_index][i];
		bool jud = false;
		for (int j = 0; j < n; j++) {
			if (i > arr[j].size() - 1) {
				result += '?';
				jud = true;
				break;
			}
			else if(word != arr[j][i]) {
				result += '?';
				jud = true;
				break;
			}
				
		}
		if (jud == false)
			result += word;

	}
	
	cout << result << endl;
}