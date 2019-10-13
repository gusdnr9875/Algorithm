#include <stdio.h>
#include <stdlib.h>
char name[16];
char word[16];
char result[16];
int l, c;

int compare(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b)
		return 1;
	else
		return -1;
	return 0;
}
void backtracking(char* wr,int pos, int cur,int ja,int mo) {

	if (pos == l) {
		if (ja >= 2 && mo >= 1) {
			wr[pos] = NULL;
			printf("%s", pos);
		}
		return;
	}

	for (int i = cur; i < c; i++) {
		if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u'){
			result[pos] = name[i];
			backtracking(wr ,pos+1, i+ 1, ja, mo + 1);
		
		}
		else {
			result[pos] = name[i];
			backtracking(wr, pos + 1, i + 1, ja+1, mo);
		}
	}

	return;
}


int main(){
	scanf("%d %d", &l, &c);
	for(int i=0;i<c;i++)
		scanf("%c", &name[i]);
	
	qsort(name, c, sizeof(int), compare);
	
	backtracking("", 0,0,0,0);

	return 0;
}