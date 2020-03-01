#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main() 
{
	int nn,tmp;
	cin >> nn;
	
	vector< vector<int> > arr;
	for (int i = 0; i < nn; i++)
	{
		vector<int> ele;
		while (1)
		{
			cin >> tmp;
			if (tmp == -1) break;

			else {
				ele.push_back(tmp);
			}
		}
		arr.push_back(ele);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < nn; i++) 
	{
		for (int j = 0; j < arr[i].size(); j++) 
		{
			cout << arr[i][j];
			if (j != arr[i].size() - 1) 
			{
				cout << " ";
			}
		}
		if (i != nn - 1)
		{
			cout << "\n";
		}
	}
	return 0;
}