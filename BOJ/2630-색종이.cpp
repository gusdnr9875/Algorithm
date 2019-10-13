#include <iostream>
using namespace std;
int arr[130][130] = { 0 };
int cnt[2] = { 0 }; //0에는 0인 부분 갯수 1엔 1인부분 갯수 
int n = 0;

void divide(int startx,int starty,int len) {
	
	if (len == 1) {
		cnt[arr[starty][startx]]++;
		return;
	}

	for(int i=starty;i<len+starty;i++)
		for(int j=startx;j<len+startx;j++)
			if (arr[starty][startx] != arr[i][j]) {
				divide(startx, starty, len / 2);
				divide(startx + len / 2, starty, len / 2);
				divide(startx, starty + len / 2, len / 2);
				divide(startx+len/2, starty + len / 2, len / 2);
				return;
			}

	cnt[arr[starty][startx]]++;
	return;

}


int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	divide(1, 1, n);

	for (int i = 0; i < 2; i++)
		cout << cnt[i] << endl;
}