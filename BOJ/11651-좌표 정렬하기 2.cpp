#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int n = 0, temp = 0;

int compare(pair<int, int> a, pair <int, int>b)
{
	if (a.second < b.second)
		return true;
	else if (a.second == b.second)
		if (a.first < b.first)
			return true;
	return false;
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;


	sort(v.begin(), v.end(),compare);
	
	
	
	for (int i = 0; i < n; i++)
		cout << v[i].first<<" "<<v[i].second << endl;


}