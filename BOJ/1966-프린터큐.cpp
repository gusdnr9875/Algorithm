#include <iostream>
using namespace std;

int arr[2010][2] = { 0 };

int main() {
	int t = 0, input = 0;
	int n = 0, m = 0;
	int start = 0, ended = 0;

	cin >> t;

	while (t--) {
		int cnt = 0;
		start = 0, ended = 0;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			cin >> input;
			arr[i][0] = i, arr[i][1] = input;
		}

		ended = n;
		while (1) {

			bool jud = true;
			for (int i = start+1; i < ended; i++)
				if (arr[i][1] > arr[start][1]) {
					jud = false;
					break;
				}
			if (arr[start][0] == m && jud == true)
				break;
			if (jud == false) {
				arr[ended][0] = arr[start][0];
				arr[ended][1] = arr[start][1];
				ended++; start++;
				
			}
			else {
				start++;
				cnt++;
			}
			
			
		}

		cout << cnt+1 << '\n';
	}
}