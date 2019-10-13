#include <iostream>
using namespace std;
int n,d;
int h, m;
char t;
int fare = 0;
int main() {

	cin >> n;
	while (n--) {
		cin >> h >> t >> m;
		cin >> d;
		
		while (d--) {
			if (h < 7)
				fare += 5;
			else if (19 <= h)
				fare += 5;
			else
				fare += 10;
			m++;
			if (m >= 60)
				m -= 60, h++;


		}
	}
	cout << fare << '\n';

}