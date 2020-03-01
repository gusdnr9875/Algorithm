#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
	int k = 3;
	vector<int> dp;
	int answer = 1000000000;
	int min = 1000000000;
	
	for (int i = k; i < stones.size(); i++) {
		int maxed = 0;
		for (int j = 1; j <= k; j++) {
			if (maxed < stones[i-j]) maxed = stones[i-j];
		}
		if (maxed < answer)answer = maxed;
	}
	for (int i = 0; i < k; i++)
		if (min > stones[i]) min = stones[i];
	if (answer > min) answer = min;
	
}