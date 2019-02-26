#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct tree {
	int num;
	char c;
	int left, right;
};
bool End; 
int chk(int c) {
	if (c >= '1' && c <= '9') return 1;
	else return 2;
}
void dfs(int i, int cur, vector<tree> &v) { 
	if (End) return;
	int left = v[i].left;
	int right = v[i].right;
	int next= chk(v[i].c);//1�̸� ���� 2�� ��ȣ
	if (left == -1 && right == -1) { //�ڽ��� ���� ���
		if (cur == next) { //�ڽ��� �θ� ��ȣ��� �ڽ��� ���ڿ�����
			End = true;
			return;
		}
		else return;
	}
	if (left != -1) dfs(left, next, v); //���� �ڽ��� �ִ� ��� �� Ÿ�� ������
	if (right != -1) dfs(right, next, v);
}
int main() {
	for (int t = 1; t <= 10; t++) {
		End = false;
		int N;
		scanf("%d", &N);
		vector<tree> v(N+1);
		int n = N / 2;
		for (int i = 1; i <= n; i++) {
			cin >> v[i].num >> v[i].c >> v[i].left >> v[i].right;
		}
		for (int i = n + 1; i <= N; i++) {
			cin >> v[i].num >> v[i].c;
			v[i].left = v[i].right = -1;
		}
		int cur=chk(v[1].c);
		dfs(1, cur, v); //root���� ����
		if (End) printf("#%d 0\n",t);
		else printf("#%d 1\n",t);
	}
	return 0;
}
