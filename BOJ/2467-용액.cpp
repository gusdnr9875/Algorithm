#include <iostream>
using namespace std;

int n = 0, front = 0, ended = 0, mid = -1;
int arr[100000] = { 0 };
int sum = -2000000001;
int result[2];
int index1, index2, cursor;
int main() {
	cin >> n;

	for (ended = 0; ended < n; ended++) {
		cin >> arr[ended];
		if (arr[ended] > 0 && mid == -1)
			mid = ended;
	}

	ended--;

	if (mid == -1) {//음수만 있는경우 
		cout << arr[ended - 1] << ' ' << arr[ended] << '\n';
		return 0;
	}
	else if (arr[0] > 0) { //양수만 있는경우
		cout << arr[0] << ' ' << arr[1] << '\n';
		return 0;
	}

	//그외에는 음수와 양수가 섞여있는형태가 나오겠지.

	cursor = ended;
	for (int i = 0; i < mid; i++) {
	
		while (1) {
			if ((arr[i] + arr[cursor]) <= 0 ) {
				if ( (arr[i] + arr[cursor]) > sum)
					sum = arr[i] + arr[cursor], result[0] = arr[i], result[1] = arr[cursor];
				break;
			}
			else if ((arr[i] + arr[cursor]) > 0 && mid<cursor) cursor--;

			else break;
		}


	}
	sum *= -1;
	//이제 양수 에서 가장 작은게 있나 확인하는 형태 
	cursor = 0;
	for (int i = ended; i >= mid; i--) {

		while (1) {
			if ((arr[i] + arr[cursor]) >= 0) {
				if(sum)
				if ((arr[i] + arr[cursor]) < sum)
					sum = arr[i] + arr[cursor], result[0] = arr[cursor], result[1] = arr[i];
				break;
			}
			else if ((arr[i] + arr[cursor]) < 0 && cursor< (mid-1)) cursor++;

			else break;
		}

	}
	if (mid >= 2)
		if (-1 * (arr[mid - 1] + arr[mid - 2]) < sum) sum = -1 * (arr[mid - 1] + arr[mid - 2]), result[0] = arr[mid-2], result[1] = arr[mid-1];
	if(arr[mid+1]!=0)
		if((arr[mid]+arr[mid+1])<sum) sum = arr[mid] + arr[mid + 1], result[0] = arr[mid], result[1] = arr[mid + 1];

	cout << result[0] << ' ' << result[1] << endl;
}