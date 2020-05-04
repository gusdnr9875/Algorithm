#include <string>
#include <vector>

using namespace std;

/*

브론즈	최근 30일간 0원 이상 10,000원 미만 구매 고객
실버	최근 30일간 10,000원 이상 20,000원 미만 구매 고객
골드	최근 30일간 20,000원 이상 50,000원 미만 구매 고객
플래티넘	최근 30일간 50,000원 이상 100,000원 미만 구매 고객
다이아몬드	최근 30일간 100,000원 이상 구매 고객*/
int date(int month, int day) {
	int result = 0;
	for (int i = 2; i <= 12; i++) {
		if (month > i) {
			if (i == 4 || i == 6 || i == 9 || i == 11)
				result += 30;
			else if (i == 2)
				result += 28;
			else
				result += 31;
		}
	}
	return result + day;
}
vector<int> solution(vector<string> purchase) {
	vector<int> answer;
	vector<pair<int, int>> tmp;
	string tmpstr = "";
	int month, day, days, price, curprice, a = 0, b = 0, c = 0, d = 0, e = 0;
	for (int i = 0; i < purchase.size(); i++) {
		tmpstr = "";
		tmpstr += purchase[i][5];
		tmpstr += purchase[i][6];
		month = stoi(tmpstr);
		tmpstr = "";
		tmpstr += purchase[i][8];
		tmpstr += purchase[i][9];
		day = stoi(tmpstr);
		days = date(month, day);
		tmpstr = "";
		for (int j = 11; j < purchase[i].length(); j++) {
			tmpstr += purchase[i][j];
		}
		price = stoi(tmpstr);
		tmp.push_back(make_pair(days, price));
	}
	for (int i = 1; i <= 365; i++) {
		curprice = 0;
		for (int j = 0; j < tmp.size(); j++) {
			if (tmp[j].first >= i - 29 && tmp[j].first <= i)
				curprice += tmp[j].second;
		}
		if (curprice < 10000)
			a++;
		else if (curprice < 20000)
			b++;
		else if (curprice < 50000)
			c++;
		else if (curprice < 100000)
			d++;
		else
			e++;
	}
	answer.push_back(a);
	answer.push_back(b);
	answer.push_back(c);
	answer.push_back(d);
	answer.push_back(e);
	return answer;
}