#include <iostream>
using namespace std;
char a[10003];
char b[10003];
char c[10003];
int acnt = 0, bcnt = 0;
int ac = 0, bc = 0;

int main() {
	cin >> a + 1 >> b + 1;
	a[0] = '0', b[0] = '0';
	
	for (int i = 1; a[i]; i++)
		acnt++;

	for (int j = 1;b[j]; j++)
		bcnt++;
	ac = acnt, bc = bcnt;
	if (acnt > bcnt)
		a[acnt + 1] = NULL;
	else
		b[bcnt + 1] = NULL;


	while (1) {
		if (acnt >= bcnt) {
			a[acnt] += b[bcnt--] - '0'; //b�� �ִ� �������� �ְ� b�� �ڸ����� �����ݴϴ�.

			if (a[acnt] > '9')
				a[acnt - 1] += 1,a[acnt]-=10;
			

			
			acnt--; //���̵� ���� 
			for (int i = acnt; i > 0;i--) {
				if (a[i] > '9')
					a[i - 1] += 1, a[i] -= 10;
			}
			if (bcnt == 0)
				break;

		}
		else {
			b[bcnt] += a[acnt--] - '0'; //b�� �ִ� �������� �ְ� b�� �ڸ����� �����ݴϴ�.

			if (b[bcnt] > '9')
				b[bcnt - 1] += 1, b[bcnt] -= 10;



			bcnt--; //���̵� ���� 
			for (int i = bcnt; i > 0; i--) {
				if (b[i] > '9')
					b[i - 1] += 1, b[i] -= 10;
			}
			if (acnt == 0)
				break;

		}

	}

	
	if (ac >= bc) //�ٵ� ���࿡ �ִ밪�̸� �� a[0]�� ���;��ϴµ�
		if (a[0] != '0')
			cout << a << endl;
		else
			cout << a+1 << endl;

	else
		if (b[0] != '0')
			cout << b << endl;
		else
			cout << b + 1 << endl;


	return 0;
}