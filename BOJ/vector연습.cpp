#include <iostream>
#include <vector>
using namespace std;



int main() {
	vector<vector<int> > v = { { 1,1 }, { 2,2 }, { 1,2 } };
	vector<int> ans;
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i][0] != v[(i + 1) % 3][0] && v[i][0] != v[(i + 2) % 3][0])
			ans.push_back(v[i][0]);
		if (v[i][1] != v[(i + 1) % 3][1] && v[i][1] != v[(i + 2) % 3][1])
			ans.push_back(v[i][1]);
	}


}