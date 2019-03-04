#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
/*16235 ���� ����ũ*/
using namespace std;
struct tree {
	int r, c, age;
};
int N, M, K;
int map[12][12];
int A[12][12];
int dr[] = {0,0,1,1,1,-1,-1,-1};
int dc[] = {1,-1,1,0,-1,1,0,-1};
vector<tree> v;
bool cmp(const tree &a, const tree &b) {
	if (a.r == b.r && a.c == b.c) return a.age < b.age;
	else {
		if (a.r == b.r) return a.c < b.c;
		else return a.r < b.r;
	}
}
int main() {
	int res = 0;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			map[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v.push_back({ x,y,z});
	}
	while (K--) {
		//�ϳ��� ĭ�� �������� ������ ���� ���, ���̰� ���� ������ ����
		sort(v.begin(), v.end(), cmp);
		vector<tree> alive, dead, spread; //����ִ� ����, ���� ����, ��Ʈ�� ������ ����
		for (int i = 0; i < v.size(); i++) {
			int r = v[i].r, c = v[i].c;
			int age = v[i].age;

			if (map[r][c] < age) dead.push_back({ r,c,age }); //���� ����� ���̺��� ������ ����
			else {
				map[r][c] -= age; //��� ���̸�ŭ ���ҽ�Ŵ 
				v[i].age++;//���� ����
				alive.push_back({ r,c,v[i].age });//alive ���Ϳ� ����
				if (v[i].age % 5 == 0) spread.push_back({ r,c,v[i].age });//���� ���̰� 5�� ������ �������� spread ���Ϳ� ����
			}
		}
		for (int i = 0; i < dead.size(); i++) { //���� ������ ����/2 ��ŭ ������� �߰�
			int r = dead[i].r, c = dead[i].c;
			int age = dead[i].age;
			map[r][c] += age / 2;
		}
		for (int i = 0; i < spread.size(); i++) { //��Ʈ���� �ϴ� ���� ��Ʈ���� alive ���Ϳ� ����
			int r = spread[i].r, c = spread[i].c;
			for (int d = 0; d < 8; d++) {
				int nr = r + dr[d], nc = c + dc[d];
				if (nr >= 1 && nc >= 1 && nr <= N && nc <= N)
					alive.push_back({ nr,nc,1 });
			}
		}
		for (int i = 1; i <= N; i++) //���� ��� �߰�
			for (int j = 1; j <= N; j++)
				map[i][j] += A[i][j];

		v.clear(); //v���� ����
		for (int i = 0; i < alive.size(); i++) {
			int r = alive[i].r, c = alive[i].c;
			int age = alive[i].age;
			v.push_back({ r,c,age }); //alive ���Ϳ� ����ִ� ������ v���Ϳ� ����
		}
		alive.clear();
		dead.clear();
		spread.clear();
		//�ʱ�ȭ����
		res = v.size(); //v ������ ũ�⸸ŭ�� ���� ����ִ� ����
	}
	printf("%d", res);
	return 0;
}
