#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>
using namespace std;
/*
#3055_Ż��
1. �� �и��� ����ġ�� ���� �ִ� ĭ�� ������ �� ĭ �� �ϳ��� �̵� ����
2. ���� �źи��� ����ִ� ĭ���� Ȯ��
3. ���� ����ġ�� ���� ����� �� ����
4. ����ġ�� ���� ���ִ� �������� �̵� ����
5. ���� ����� �ұ��� �̵��� �� ����
6. ����ġ�� �����ϰ� ����� ���� �̵��ϱ� ���� �ʿ��� �ּ� �ð�
7. ����ġ�� ���� �� ������ ĭ���� �̵� �Ұ� 
8. ��� �ұ��� �̵� ���ϸ� KAKTUS ���
*/
int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };
int visit[101][101];
char map[101][101];
int res = 0;
int n, m;
bool escape = false;
int main() {
	cin >> n >> m;
	queue<pair<int, int>> heg;
	queue<pair<int, int>>water;
	int Dr, Dc;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				visit[i][j] = 1;
				heg.push({ i,j });
			}
			else if (map[i][j] == '*') water.push({ i,j });
		}
	}
	while (!heg.empty()) {
		int w = water.size();
		int h = heg.size();
		//�� ��������
		for (int i = 0; i < w; i++) {
			int r = water.front().first;
			int c = water.front().second;
			water.pop();

			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				if (nr<0 || nc<0 || nr >= n || nc >= m) continue;
				if (map[nr][nc]=='*' || map[nr][nc] == 'D'|| map[nr][nc] == 'X') continue;
				map[nr][nc] = '*';
				water.push({ nr,nc });
			}
		}
		for (int i = 0; i < h; i++) {
			int r = heg.front().first;
			int c = heg.front().second;
			heg.pop();

			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				if (visit[nr][nc]||nr<0||nc<0 ||nr>=n ||nc>=m) continue;
				if (map[nr][nc] == '*'|| map[nr][nc] == 'X') continue;
				if (map[nr][nc] == 'D'|| map[nr][nc] == 'A') {
					escape = true;
					break;
				}
				visit[nr][nc] = 1;
				heg.push({ nr,nc });
			}
			if (escape) break;
		}
		res++;
		if (escape) break;
	}
	if(escape) cout << res<< endl;
	else cout << "KAKTUS" << endl;
	return 0;
}