#include <iostream>
using namespace std;
int arr[501][501] = { 0 };
int rowcnt[501] = { 0 };
int colcnt[501] = { 0 };
int main() {
	int n = 0, m = 0,input,maxx=0,total=0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> input;

			while (input) {
				if (input % 10 == 9)
					arr[i][j]++;
				input /= 10;
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			rowcnt[i] += arr[i][j];

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			colcnt[i] += arr[j][i];

			
	for (int i = 0; i < n; i++) {
		if (rowcnt[i] > maxx) maxx = rowcnt[i];
		total += rowcnt[i];
	}
	for(int i=0;i<m;i++)
		if (colcnt[i] > maxx) maxx = colcnt[i];

	cout << total - maxx << endl;
	
	

}