#include <iostream>
using namespace std;

int main() {
	int arr[3] = { 0 };

	while (1)
	{
		bool jud = false;
		cin >> arr[0] >> arr[1] >> arr[2];
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;

		for (int i = 0; i < 3; i++)
			arr[i] *= arr[i];
		for (int i = 0; i < 3; i++) {
			int sum = 0;
			for (int j = 0; j < 3; j++)
				if (arr[i] != arr[j])
					sum += arr[j];
			if (sum == arr[i]) {
				jud = true;
				break;
			}
		}
		if (jud == true) cout << "right" << '\n';
		else cout << "wrong" << '\n';

	}

}