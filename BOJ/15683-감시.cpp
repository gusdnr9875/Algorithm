#include <iostream>
using namespace std;
void cctv1(int d, int cnt);
void cctv2(int d, int cnt);
void cctv3(int d, int cnt);
void cctv4(int d, int cnt);
void cctv5(int d, int cnt);
typedef struct c {
	int x, y;
	int num;
}tv;

tv cctv[64];
int cctv_len = 0;
int n = 0, m = 0;
int arr[9][9] = { 0 };
int result = 1000;
void dfs(int cnt,int current) {

	if (cnt == (cctv_len)){
		int sum = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (arr[i][j] == 0) sum++;
		if (result > sum) result = sum;

		
		return;
	}

	for (int i = current; i < cctv_len; i++) {
		if(cctv[i].num==1)
			cctv1(i,cnt);
		else if (cctv[i].num == 2) 
			cctv2(i, cnt);
		else if (cctv[i].num == 3)
			cctv3(i, cnt);
		else if (cctv[i].num == 4)
			cctv4(i, cnt);
		else if (cctv[i].num == 5)
			cctv5(i, cnt);
	}



}
void cctv1(int d,int cnt) {
	int yy = cctv[d].y;
	int xx = cctv[d].x;
	//���������� �޿�� 
	for (int i = xx + 1; i <= m; i++) {
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == 0)
			arr[yy][i] = -d+100;
	}
	dfs(d + 1, cnt + 1);
	for (int i = xx + 1; i <= m; i++) //�ٽ� ���� 
	{
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == (-d + 100))
			arr[yy][i] = 0;
	}
	//�������� �޿� 
	for (int i = xx - 1; i >= 1; i--) {
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == 0)
			arr[yy][i] = -d + 100;
	}
	dfs(d + 1, cnt + 1);
	for (int i = xx - 1; i >= 1; i--) { //����
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == (-d + 100))
			arr[yy][i] = 0;
	}
	//���� �޿� 
	for (int i = yy - 1; i >= 1; i--)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == 0)
			arr[i][xx] = -d + 100;
	}
	dfs(d + 1, cnt + 1);
	for (int i = yy - 1; i >= 1; i--)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == (-d + 100))
			arr[i][xx] = 0;
	}
	//�Ʒ��� �޿� 

	for (int i = yy + 1; i <= n; i++)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == 0)
			arr[i][xx] = -d + 100;
	}
	dfs(d + 1, cnt + 1);
	for (int i = yy + 1; i <= n; i++)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == -d + 100)
			arr[i][xx] = 0;
	}
}

void cctv2(int d, int cnt) {

	int yy = cctv[d].y;
	int xx = cctv[d].x;
	

	//�� ���� 
	for (int i = xx + 1; i <= m; i++) {
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == 0)
			arr[yy][i] = -d + 100;
	}
	for (int i = xx - 1; i >= 1; i--) {
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == 0)
			arr[yy][i] = -d + 100;
	}
	dfs(d + 1, cnt + 1);
	for (int i = xx + 1; i <= m; i++) //����������
	{
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == (-d + 100))
			arr[yy][i] = 0;
	}
	for (int i = xx - 1; i >= 1; i--) { // ��������
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == (-d + 100))
			arr[yy][i] = 0;
	}

	//���Ʒ� 
	for (int i = yy - 1; i >= 1; i--)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == 0)
			arr[i][xx] = -d + 100;
	}
	for (int i = yy + 1; i <= n; i++)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == 0)
			arr[i][xx] = -d + 100;
	}
	dfs(d + 1, cnt + 1);
	for (int i = yy - 1; i >= 1; i--)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == (-d + 100))
			arr[i][xx] = 0;
	}
	for (int i = yy + 1; i <= n; i++)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == -d + 100)
			arr[i][xx] = 0;
	}
}

void cctv3(int d, int cnt) {

	int yy = cctv[d].y;
	int xx = cctv[d].x;
	//��,������
	for (int i = xx + 1; i <= m; i++) {
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == 0)
			arr[yy][i] = -d + 100;
	}
	for (int i = yy - 1; i >= 1; i--)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == 0)
			arr[i][xx] = -d + 100;
	}
	dfs(d + 1, cnt + 1);
	for (int i = xx + 1; i <= m; i++) //�ٽ� ���� 
	{
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == (-d + 100))
			arr[yy][i] = 0;
	}
	for (int i = yy - 1; i >= 1; i--)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == (-d + 100))
			arr[i][xx] = 0;
	}
	//������ �Ʒ�
	for (int i = xx + 1; i <= m; i++) {
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == 0)
			arr[yy][i] = -d + 100;
	}
	for (int i = yy + 1; i <= n; i++)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == 0)
			arr[i][xx] = -d + 100;
	}
	dfs(d + 1, cnt + 1);
	for (int i = xx + 1; i <= m; i++) //�ٽ� ���� 
	{
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == (-d + 100))
			arr[yy][i] = 0;
	}
	for (int i = yy + 1; i <= n; i++)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == -d + 100)
			arr[i][xx] = 0;
	}
	//�Ʒ� ����
	for (int i = yy + 1; i <= n; i++)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == 0)
			arr[i][xx] = -d + 100;
	}
	for (int i = xx - 1; i >= 1; i--) {
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == 0)
			arr[yy][i] = -d + 100;
	}
	dfs(d + 1, cnt + 1);
	for (int i = yy + 1; i <= n; i++)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == -d + 100)
			arr[i][xx] = 0;
	}
	for (int i = xx - 1; i >= 1; i--) { //����
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == (-d + 100))
			arr[yy][i] = 0;
	}

	//���� ��

	for (int i = xx - 1; i >= 1; i--) {
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == 0)
			arr[yy][i] = -d + 100;
	}
	for (int i = yy - 1; i >= 1; i--)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == 0)
			arr[i][xx] = -d + 100;
	}
	dfs(d + 1, cnt + 1);
	for (int i = xx - 1; i >= 1; i--) { //����
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == (-d + 100))
			arr[yy][i] = 0;
	}
	for (int i = yy - 1; i >= 1; i--)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == (-d + 100))
			arr[i][xx] = 0;
	}
}
void cctv4(int d, int cnt) {
	// �� ���� ������
	int yy = cctv[d].y;
	int xx = cctv[d].x;

	for (int i = yy - 1; i >= 1; i--) //��
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == 0)
			arr[i][xx] = -d + 100;
	}
	for (int i = xx - 1; i >= 1; i--) { //��
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == 0)
			arr[yy][i] = -d + 100;
	}
	for (int i = xx + 1; i <= m; i++) { //��
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == 0)
			arr[yy][i] = -d + 100;
	}

	dfs(d + 1, cnt + 1);
	//�� ���� 
	for (int i = xx - 1; i >= 1; i--) { //����
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == (-d + 100))
			arr[yy][i] = 0;
	}
	//�Ʒ� �߰� 
	for (int i = yy + 1; i <= n; i++)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == 0)
			arr[i][xx] = -d + 100;
	}
	dfs(d + 1, cnt + 1);
	//�� ���� 
	for (int i = yy - 1; i >= 1; i--)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == (-d + 100))
			arr[i][xx] = 0;
	}
	//�� �߰�
	for (int i = xx - 1; i >= 1; i--) {
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == 0)
			arr[yy][i] = -d + 100;
	}
	dfs(d + 1, cnt + 1);
	//�� ���� 
	for (int i = xx + 1; i <= m; i++) //�ٽ� ���� 
	{
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == (-d + 100))
			arr[yy][i] = 0;
	}
	//�� �߰� 
	for (int i = yy - 1; i >= 1; i--)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == 0)
			arr[i][xx] = -d + 100;
	}
	dfs(d + 1, cnt + 1);


	//�� �� �Ʒ� ������ ���� 
	for (int i = yy - 1; i >= 1; i--)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == (-d + 100))
			arr[i][xx] = 0;
	}
	for (int i = xx - 1; i >= 1; i--) { //����
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == (-d + 100))
			arr[yy][i] = 0;
	}
	for (int i = yy + 1; i <= n; i++)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == -d + 100)
			arr[i][xx] = 0;
	}

}

void cctv5(int d, int cnt) {
	int yy = cctv[d].y;
	int xx = cctv[d].x;
	//������ ���� �Ʒ� �� 
	for (int i = xx + 1; i <= m; i++) {
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == 0)
			arr[yy][i] = -d + 100;
	}
	for (int i = xx - 1; i >= 1; i--) {
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == 0)
			arr[yy][i] = -d + 100;
	}
	for (int i = yy + 1; i <= n; i++)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == 0)
			arr[i][xx] = -d + 100;
	}
	for (int i = yy - 1; i >= 1; i--)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == 0)
			arr[i][xx] = -d + 100;
	}
	dfs(d + 1, cnt + 1);
	for (int i = yy - 1; i >= 1; i--)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == (-d + 100))
			arr[i][xx] = 0;
	}
	for (int i = yy + 1; i <= n; i++)
	{
		if (arr[i][xx] == 6)
			break;
		else if (arr[i][xx] == -d + 100)
			arr[i][xx] = 0;
	}
	for (int i = xx - 1; i >= 1; i--) { //����
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == (-d + 100))
			arr[yy][i] = 0;
	}
	for (int i = xx + 1; i <= m; i++) //�ٽ� ���� 
	{
		if (arr[yy][i] == 6)
			break;
		else if (arr[yy][i] == (-d + 100))
			arr[yy][i] = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5)
				cctv[cctv_len].x = j, cctv[cctv_len].y = i, cctv[cctv_len++].num=arr[i][j];
		}

	dfs(0,0);

	cout << result << '\n';
}