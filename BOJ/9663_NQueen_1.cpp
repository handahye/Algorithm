#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
using namespace std;
/*Ǯ�� 1*/
int visit[11];
int N, ans;
bool chk(int i) {
	for (int j = 0; j < i; j++) {//0���� i����� ���� �� Ȥ�� �밢���� ��ġ �ϴ� ���� �ִ���
		if (visit[j] == visit[i] || abs(visit[i] - visit[j]) == (i - j))
			return false;
		//i��� j���� �� ���� �Ȱ����� ���� �� ����
		//i��� j���� �� ���� �밢���� ��ġ�ϴ� ���밪�̸� �ȵ�
	}
	return true;
}
void dfs(int i) {
	if (i == N) { //N���� ��� �� ���
		ans += 1;
		return;
	}
	for (int j = 0; j < N; j++) { //������ġ ã��
		visit[i] = j; //i�� j���� ���� ������ (i,j)
		if (chk(i)) //���� �ڸ��� ���� ���� �� �ִ���
			dfs(i + 1);//���� ������
	}
}
int main() {
	cin >> N;
	ans = 0;
	dfs(0);
	cout << ans << endl;
	return 0;
}
