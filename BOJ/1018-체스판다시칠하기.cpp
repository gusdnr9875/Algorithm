#include <iostream>
using namespace std;
int n = 0,m = 0;
char arr[52][52] = { 0 };
int mini = 1000000000;

void search(int startx,int starty) {
	int wb = 0, bw = 0;
	for(int i=starty;i<starty+8;i++)
		for (int j = startx; j < startx + 8; j++) {
			if ((i - starty+2) % 2 == 0) { //에러 생길까봐 
				if ((j - startx + 2) % 2 == 0) {
					if (arr[i][j] == 'B')
						wb++;
				}
				else {
					if (arr[i][j] == 'W')
						wb++;
				}

			}
			else {
				if ((j - startx + 2) % 2 == 0) {
					if (arr[i][j] == 'W')
						wb++;
				}
				else {
					if (arr[i][j] == 'B')
						wb++;
				}
			}
		}
	if (mini > wb) mini =wb;



	for (int i = starty; i<starty + 8; i++)
		for (int j = startx; j < startx + 8; j++) {
			if ((i - starty + 2) % 2 == 0) { //에러 생길까봐 
				if ((j - startx + 2) % 2 == 0) {
					if (arr[i][j] == 'W')
						bw++;
				}
				else {
					if (arr[i][j] == 'B')
						bw++;
				}

			}
			else {
				if ((j - startx + 2) % 2 == 0) {
					if (arr[i][j] == 'B')
						bw++;
				}
				else {
					if (arr[i][j] == 'W')
						bw++;
				}
			}
		}
	if (mini > bw) mini = bw;


}


int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i] + 1;

	for (int i = 1; i <= n - 7; i++)
		for (int j = 1; j <= m - 7; j++)
			search(j, i);

	cout << mini << '\n';

}