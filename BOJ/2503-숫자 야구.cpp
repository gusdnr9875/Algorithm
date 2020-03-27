#include <iostream>
#include <algorithm>
using namespace std;
int n = 0, result = 0;
int arr[100][3] = { 0 };
int arr2[9] = { 0 };
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	for (int i = 100; i <= 999; i++) {
		if (i % 10 == 0) continue; //0 안들어가게
		if ((i / 10) % 10 == 0) continue;

		if (i / 100 == (i / 10) % 10) continue;
		if (i / 100 == i % 10) continue;
		if (i % 10 == (i / 10) % 10) continue;
		bool jud = true;

		for (int j = 0; j < n; j++) {
			for (int k = 1; k <= 9; k++) arr2[k] = 0;
			bool first = false, second = false, third = false;

			int strike = 0, ball = 0;
			int num = i;
			
			if (num / 100 == arr[j][0] / 100) strike++,first=true;
			arr2[arr[j][0] / 100]++;

			if ((num / 10) %10 == (arr[j][0] / 10)%10) strike++,second=true;
			arr2[(arr[j][0] / 10) % 10]++;

			if (num % 10 == arr[j][0] % 10) strike++,third=true;
			arr2[arr[j][0] % 10]++;
			
			if (!first&&arr2[num / 100]) ball++;
			if (!second&&arr2[(num / 10) % 10]) ball++;
			if (!third&&arr2[num % 10]) ball++;

			if (strike != arr[j][1] || ball != arr[j][2]) {
				jud = false;
				break;
			}

		}
		if (jud == true) {
			
			result++;
		}
	}
	cout << result << endl;
	return 0;
}