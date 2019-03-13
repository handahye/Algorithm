#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;
int map[51][51];
int visit[51][51];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int N, L, R;
bool End=false;
void bfs(int i, int j) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;//����
	q.push({ i,j });
	v.push_back({ i,j });
	int sum = map[i][j]; //������ �� �α���
	visit[i][j] = true;
	while (!q.empty()) {//���� ���ϱ� ���� bfs
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d], nc = c + dc[d];
			if (nr >= 0 && nc >= 0 && nr < N && nc < N &&!visit[nr][nc]) {
				if (abs(map[r][c] - map[nr][nc]) >= L && abs(map[r][c] - map[nr][nc]) <= R) {
					visit[nr][nc] = true; //L�̻� R���ϸ� �����̴ϱ� queue�� vector�� �߰�
					q.push({ nr,nc });
					v.push_back({ nr,nc });
					sum += map[nr][nc];//�α��� ������
				}
			}
		}
	}

	if (v.size() > 1) {//vector ����� 1���� ũ�� ������ ��������Ŵϱ�
		End = true;
		int num = sum / v.size(); //������ ���� sum�� ���ռ��� ������
		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second] = num;//map ����
		}
	}
}
int main() {
	int res = 0;
	scanf("%d%d%d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		End = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) bfs(i, j);
			}
		}
		if (!End) break; //������ ��������� �ʾ����� ��������
		res++;//������ ������� �α��̵��� ������ 
		memset(visit, 0, sizeof(visit));
	}
	printf("%d", res);
	return 0;
}