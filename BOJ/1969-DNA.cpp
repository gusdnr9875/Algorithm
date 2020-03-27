#include <iostream>
#include <string>
using namespace std;

int n, m;
string word[1000];
int result_sum = 0;
string result;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> word[i];
	


	for (int i = 0; i < m; i++) {
		int arr[26] = { 0 }, maxed = 0, max_index = 0;
		for (int j = 0; j < n; j++) {
			arr[word[j][i] - 'A']++; 
		}
		for (int j = 0; j < 26; j++) {
			if (maxed < arr[j]) maxed = arr[j],max_index = j;
		}
		result_sum += n - maxed;
		result += max_index + 'A';
	}

	cout << result << endl;
	cout << result_sum << endl;

}