#include <iostream>
using namespace std;
int kk = 0;
char kkk[10]; //부등호 넣음
char k[10];

char asending[10];
char desending[10];
int acur = 0, dcur = 0;
int main() {
	cin >> kk;

	for (int i = 0; i < kk; i++) 
		cin >> kkk[i];

	for (int i = 0; i < 10; i++)
		k[i] = '0';

	for (int i = 0; i < kk; i++)
	{
		if (kkk[i] == '>') {
			for (int j = 9; j >= 0; j--)
				if (k[j] == '0') {
					k[j] = '1';
					asending[acur++] = '0'+ j;
					break;
				}
		}
		else {
			int cnt = 1;
			for (int j = i + 1; j < kk; j++) {
				if (kkk[j] == '>')
					break;
				cnt++;
			}

			for (int j = 9; j >= 0; j--) {
				if (k[j] == '0')
					cnt--;
				if (cnt == -1&&k[j]=='0') {
					asending[acur++] = '0' + j;
					k[j] = '1';
					break;
				}
			}
		}

	}
	for (int i = 9; i>=0; i--)
		if (k[i] == '0') {
			asending[acur++] = '0' + i;
			break;
		}



	for (int i = 0; i <= 9; i++)
		k[i] = '0';





	for (int i = 0; i < kk; i++) {
		if (kkk[i] == '<') {
			for (int j = 0; j <= 9; j++)
				if (k[j] == '0') {
					k[j] = '1';
					desending[dcur++] = '0' + j;
					break;
				}
		}
		else {

			int cnt = 1;
			for (int j = i + 1; j < kk; j++) {
				if (kkk[j] == '<')
					break;
				cnt++;
			}
			//cout << cnt << endl;
			for (int j = 0; j <= 9; j++) {
				if (k[j] == '0')
					cnt--;
				if (cnt == -1 && k[j] == '0') {
					desending[dcur++] = '0' + j;
					k[j] = '1';
					break;
				}
			}

		}
	}


	for (int i = 0; i <= 9; i++)
		if (k[i] == '0') {
			desending[dcur++] = '0' + i;
			break;
		}


	printf("%s\n", asending);
	printf("%s\n", desending);
	
}