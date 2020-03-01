#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string basic,bomb;
char result[1000001];
int  result_cur = 0;
int main() {
	char lastword;
	cin >> basic;
	cin >> bomb;
	lastword = bomb[bomb.size() - 1];

	for (int i = 0; i < basic.size(); i++) {
		result[result_cur++] = basic[i];
	

		if (basic[i] == lastword) //마지막 문자열과 다르면 스택에 담습니다.
		 { 
			
				bool jud = true;
				for (int j = bomb.size() - 1; j >= 0; j--)
				{
					if (bomb[j] != result[result_cur - 1 - (bomb.size() - 1) + j]) { // 스택의 가장위쪽부터 한칸씩 내려오면서 검사
						jud = false; //즉 해당문자열이 아니면 false
						break;
					}
				}
				if (jud == false) {
					continue;
				}
				else { 
								
					for (int j = 0; j < bomb.size(); j++) {
						result_cur--;				
					}
				}	
		}
	}
	if (result_cur==0)
		cout << "FRULA" << '\n';
	else {
		
		for (int i = 0; i < result_cur; i++) {
			cout << result[i];
		}
		cout << '\n';
	}
}
