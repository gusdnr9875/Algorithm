#include <iostream>
#include <algorithm>
using namespace std;
int n = 0;
bool jud = false;
typedef struct time {
	int begin;
	int end;
};
int cursor = 0, result = 0;

time arr[100000];

bool compare(const time& i,const time& j) {
	if (i.end < j.end) return true;

	else if (i.end == j.end) {
		return i.begin< j.begin;
	}

	return false;

}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].begin >> arr[i].end;

	sort(arr, arr + n,compare);
	
	int i = 0;
	while(i<n) {
		result++;
		int endtime = arr[i].end;
		i++;
		while (arr[i].begin < endtime) {
			i++;
		}
	
	}
	cout << result << '\n';
}