#include <iostream>
using namespace std;
int n=1, r, c, n_2=1;
int x = 1, y = 1;
int sum = 0;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n_2 >> r >> c;
	r++, c++; // 4,2 �� �ٲ����� 
	for (int i = 0; i < n_2; i++)
		n *= 2;

	while (1) {
		if (x == c && y == r) break;
		int jx = (n + x);
		int jy = (n + y);
		if ((n / 2 + x) > c && (n / 2 + y) > r)  //1��и�
			n /= 2;
		else if ( (n/ 2 +x) <= c && (n / 2 + y) <= r) { //4��и� 
			sum += (n / 2)*(n / 2) * 3; //1,2,3 ��и� ������ ����
			n /= 2; 
			x = x + n, y = y + n;
		}
		else if ((n / 2 + x) > c && (n / 2 + y) <= r) { //3��и� 
			sum += (n / 2)*(n / 2) * 2; //1,2��и� ������ ����
			n /= 2;
			y = y + n;
		}
		else if ((n / 2 + x)<= c && (n / 2 + y) > r) { //2��и� 
			sum += (n / 2)*(n / 2) * 1; //1��и� ������ ����
			n /= 2;
			x = x + n;
		}
	
	
	}
	cout << sum << '\n';
}