#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;



int solution(vector<string> ip_addrs, vector<string> langs, vector<int> scores) {
	int answer = 0;
	bool arr[100001] = { 0 };
	for (int i = 0; i < ip_addrs.size(); i++) {
		int cnt = 1;
		queue <int> que;
		que.push(i);
		for (int j = 0; j < ip_addrs.size(); j++) {
			if (i == j) continue;
			if (!ip_addrs[i].compare(ip_addrs[j])) {
				cnt++;
				que.push(j);
			}
		}


		if (cnt >= 4) {
			while (!que.empty()) {
				int x = que.front();
				que.pop();
				arr[x] = 1;
			}
		}


		else if (cnt == 3) {
			int x1 = que.front();
			que.pop();
			int x2 = que.front();
			que.pop();
			int x3 = que.front();
			que.pop();

			if (langs[x1].at(0) == langs[x2].at(0) && langs[x1].at(0) == langs[x3].at(0) && langs[x1].at(0) == 'C')
				arr[x1] = 1, arr[x2] = 1, arr[x3] = 1;
			else if (langs[x1].compare(langs[x2])==0 && langs[x2].compare(langs[x3])== 0)
				arr[x1] = 1, arr[x2] = 1, arr[x3] = 1;

		}
		else if (cnt == 2) {
			int x1 = que.front();
			que.pop();
			int x2 = que.front();
			que.pop();

			if (scores.at(x1) == scores.at(x2)) {
				if (langs[x1].at(0) == langs[x2].at(0) && langs[x1].at(0) == 'C')
					arr[x1] = 1, arr[x2] = 1;
				else if (langs[x1].compare(langs[x2]) == 0)
					arr[x1] = 1, arr[x2] = 1;
			}
		}
	}


	for (int i = 0; i < ip_addrs.size(); i++) {
		if (arr[i] == 0)
			answer++;
	}


	return answer;
}

int main() {


}