#include <iostream>
using namespace std;
char arr[101];


int main(){
	cin >> arr;
	int key ;
	for (int i = 1; i < 100; i++)
	{
		if ((arr[0] ^ i) == 67 && (arr[1] ^ i) == 72) {
			key = i;
			cout << key << endl;
			break;
		}
	}
	for (int i = 0; arr[i]; i++) {
		arr[i] = arr[i] ^ key;
	}
	printf("%s\n", arr);
	return 0;
}