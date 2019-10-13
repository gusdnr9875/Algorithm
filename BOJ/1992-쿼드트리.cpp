#include <iostream>
using namespace std;

char arr[65][65];
int n = 0;

void divided(int startx,int starty,int num) {
	if (num == 1) {
		cout << arr[starty][startx] ;
		return;
	}
	bool jud = true;
	
	for (int i = starty; i < num+starty; i++)
		for (int j = startx; j < num+startx; j++)
			if (arr[i][j] != arr[starty][startx]) {
				cout << "(";
				divided(startx,starty , num / 2);
				divided(num/2+startx, starty, num / 2);
				divided(startx, num / 2+starty, num / 2);
				divided(num / 2+startx, num / 2+starty, num / 2);
				jud = false;
				cout << ")";
				return;
			}
	if (jud == true)
		cout << arr[starty][startx];


	
}



int main() {

	cin >> n;

	for (int i = 1; i <= n; i++)
		scanf("%s",&arr[i][1]);

	divided(1,1,n);
	cout << '\n';

}