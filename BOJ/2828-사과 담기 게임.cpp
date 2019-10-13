#include <iostream>
#include <math.h>
using namespace std;
int input = 0;

int main() {
	int m, n, j, sum = 0;
	int mini, maxi;
	cin >> m >> n >> j;
	mini = 1, maxi = n;

	while (j--) {
		cin >> input;
		
		if (input >= mini&& input <= maxi)
			continue;
		if (input < mini) {
			sum += mini - input;
			maxi = maxi - (mini - input);
			mini = input;
		}
		else {
			sum += input - maxi;
			mini = mini + (input - maxi);
			maxi = input;
			
		}
	}
	cout << sum << endl;

}