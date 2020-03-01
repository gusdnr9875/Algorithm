#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;


int main() {
	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> banned_id = { "fr*d*", "abc1**" };
	vector<int> cnt;
	int answer = 0;
	int sum = 1;
	bool a = false;
	for (int i = 0; i < user_id.size(); i++) {
		string id = user_id[i];
		for (int j = 0; j < banned_id.size(); j++) {
			string bid = banned_id[j]; // 배너아이디
			if (id.compare(bid) == 0) //같으면 
				cnt[j]++;
		}
		
	}
	for (int j = 0; cnt.size(); j++)
		if (cnt[j] > 1)  a = true, sum *= j;
	if (a == true) cout << sum;
	else cout << 0;
	return answer;
}
