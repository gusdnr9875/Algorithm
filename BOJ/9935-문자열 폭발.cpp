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
	

		if (basic[i] == lastword) //������ ���ڿ��� �ٸ��� ���ÿ� ����ϴ�.
		 { 
			
				bool jud = true;
				for (int j = bomb.size() - 1; j >= 0; j--)
				{
					if (bomb[j] != result[result_cur - 1 - (bomb.size() - 1) + j]) { // ������ �������ʺ��� ��ĭ�� �������鼭 �˻�
						jud = false; //�� �ش繮�ڿ��� �ƴϸ� false
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
