#include <iostream>
using namespace std;

int arr[2189][2189] = { 0 };
int cnt[3] = { 0 }; //0 -1 1 0 2 1
int n = 0;

void divided(int startx, int starty, int num) {
	if (num == 1) {
		int s = arr[starty][startx];
		cnt[s + 1]++;
		return;
	}
	bool jud = true;

	for (int i = starty; i < num + starty; i++)
		for (int j = startx; j < num + startx; j++)
			if (arr[i][j] != arr[starty][startx]) {
				
				divided(startx, starty, num / 3);
				divided(num / 3 + startx, starty, num / 3);
				divided(startx, num / 3 + starty, num / 3);
				divided(num / 3 + startx, num / 3 + starty, num / 3);

				divided(2*(num / 3) + startx, starty, num / 3);
				divided(2*(num / 3) + startx, num / 3 + starty, num / 3);

				divided(startx, 2*(num / 3) + starty, num / 3);
				divided(num / 3 + startx, 2 * (num / 3) + starty, num / 3);
				divided(2*(num / 3) + startx, 2 * (num / 3) + starty, num / 3);

				jud = false;
				
				return;
			}
	if (jud == true) {
		int s = arr[starty][startx];
		cnt[s + 1]++;

	}
		



}



int main() {

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	divided(1, 1, n);
	for (int i = 0; i <= 2; i++)
		cout << cnt[i]<<'\n';

}