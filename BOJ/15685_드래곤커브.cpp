#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
#15685_�巡�� Ŀ��
[����]
1. �巡�� Ŀ��� 1) ���� ��, 2) ���� ����, 3) ����� �̷����
2. 2-1) 0���� �巡�� Ŀ��� ���̰� 1�� ����
	2-2) 1���� �巡�� Ŀ��� 0������ ������ �������� �ð�������� 90�� ȸ����Ų ��,
	0���� �巡�� Ŀ���� �� ���� ���� ��
	2-3) �� ����� �̿��ؼ� ���밡 �̾���
3. �� K���� �巡�� Ŀ��� K-1���� �巡�� Ŀ�긦 �� �� �������� 90�� �ð� ���� ��Ų ����, 
�װ��� �� ���� ���� ��.

[������ ��]
1. x, y �ݴ� 
*/
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int visit[102][102] = { 0, };
int nx, ny;
int dirChange(int dir) {
	if (dir == 0) return 1;
	else if (dir == 1) return 2;
	else if (dir == 2) return 3;
	else if (dir == 3) return 0;
}
void dragonCurve(vector<int> &v) {
	for (int i = v.size() - 1; i >= 0; i--) { //vector�� ���������� �����ؾ���
		int d = dirChange(v[i]);
		nx = nx + dx[d];
		ny = ny + dy[d];
		visit[nx][ny] = 1;
		v.push_back(d);
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> y >> x >> d >> g; 
		vector<int> dragon;
		visit[x][y] = 1;
		nx = x + dx[d], ny = y + dy[d];
		visit[nx][ny] = 1;
		dragon.push_back(d);

		for (int i = 0; i < g; i++) //���� ��ŭ ������
			dragonCurve(dragon);
	}
	int res = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (visit[i][j] && visit[i][j + 1] && visit[i + 1][j] && visit[i+1][j + 1])
				res++;
		}
	}
	printf("%d", res);
	return 0;
}