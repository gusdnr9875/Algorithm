#include<iostream>
#include<string>
using namespace std;
int a = 0, b = 0;

int main()
{
	string s; cin >> s;
	bool jud = false;
	for (int i = 1; i < s.size(); ++i)
	{
		string s1 = s.substr(0, i);
		string s2 = s.substr(i, s.size());
		 a = 1, b = 1;
		for (int i = 0; i < s1.size(); ++i)
		{
			a *= (s1[i] - '0');
		}
		for (int i = 0; i < s2.size(); ++i)
		{
			b *= (s2[i] - '0');
		}
		if (a == b) {
			jud = true;
			break;
		}
	}
	if (jud)cout << "YES" << endl;
	else cout << "NO" << endl;
}
