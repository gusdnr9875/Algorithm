#include <iostream>
using namespace std;
int arr[3][2] = { 0 };
int resultx = 0,resulty=0;
int main() {
	bool jud = false;
	for (int i = 0; i < 3; i++)
		cin >> arr[i][0] >> arr[i][1];

	for (int i = 0; i < 3; i++) {
		jud = false;
		for (int j = 0; j < 3; j++)
			if (i != j&&arr[i][0] == arr[j][0]) {
				jud = true;
				break;
			}

		if (jud == false)
			resultx = arr[i][0];
	}

	for (int i = 0; i < 3; i++) {
		jud = false;
		for (int j = 0; j < 3; j++)
			if (i != j&&arr[i][1] == arr[j][1]) {
				jud = true;
				break;
			}

		if (jud == false)
			resulty = arr[i][1];
	}


	cout << resultx << " " << resulty << endl;

}