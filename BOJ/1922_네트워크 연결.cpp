 #include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<set>
using namespace std;
/*ũ�罺Į �˰���*/
int N, M, res;
int parent[100001];
vector <pair<int, pair<int, int>>> e;
int find(int x) { //�θ��� ã��
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}
void Union(int x, int y) {//�θ��尡 �ٸ��� ������
	x = find(x);
	y = find(y);
	if (x != y) parent[y] = x;//x�� �θ���� y�� �θ��带 �ٲ���
}
bool sameParent(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	else return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		e.push_back({ c,{a,b} });
	}
	sort(e.begin(), e.end());
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < M; i++) {
		int u = e[i].second.first, v = e[i].second.second;
		if (!sameParent(u, v)) {//�θ��尡 �ٸ���
			Union(u, v);//�̾��ش�
			res += e[i].first;
		}
	}
	printf("%d", res);
	return 0;
}