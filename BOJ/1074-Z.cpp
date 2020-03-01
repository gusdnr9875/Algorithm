#include <iostream>
using namespace std;
int n=1, r, c, n_2=1;
int x = 1, y = 1;
int sum = 0;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n_2 >> r >> c;
	r++, c++; // 4,2 로 바꿔주지 
	for (int i = 0; i < n_2; i++)
		n *= 2;

	while (1) {
		if (x == c && y == r) break;
		int jx = (n + x);
		int jy = (n + y);
		if ((n / 2 + x) > c && (n / 2 + y) > r)  //1사분면
			n /= 2;
		else if ( (n/ 2 +x) <= c && (n / 2 + y) <= r) { //4사분면 
			sum += (n / 2)*(n / 2) * 3; //1,2,3 사분면 값들을 저장
			n /= 2; 
			x = x + n, y = y + n;
		}
		else if ((n / 2 + x) > c && (n / 2 + y) <= r) { //3사분면 
			sum += (n / 2)*(n / 2) * 2; //1,2사분면 값들을 저장
			n /= 2;
			y = y + n;
		}
		else if ((n / 2 + x)<= c && (n / 2 + y) > r) { //2사분면 
			sum += (n / 2)*(n / 2) * 1; //1사분면 값들을 저장
			n /= 2;
			x = x + n;
		}
	
	
	}
	cout << sum << '\n';
}