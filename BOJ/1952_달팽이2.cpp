#include <iostream>
#include <algorithm>
#include<vector>
#include <string>
using namespace std;
/*
#1952_������2
1. ǥ�� �� �Ǵ� �̹� �׷��� ĭ�� ������ ���̻� �̵��� �� ����,
�ð� �������� ���� ��� �׷�����
2. ǥ�� ��� ä���� ������, ���� �� �� ������?
*/
int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };
int visit[101][101];
int res = 0;
int m, n;
bool End = false;
void dfs(int total, int cnt, int r, int c, int dir) {
	if (End) return;
	if (total - cnt == m * n) {
		End = true;
		return;
	}
	res = cnt;
	int nr = r + dr[dir];
	int nc = c + dc[dir];
	if (nr < 0 || nc < 0 || nr >= m || nc >= n || visit[nr][nc]) {
		dir = (dir + 1) % 4;
		dfs(total+1, cnt + 1, r, c, dir);
	}
	visit[nr][nc] = 1;
	dfs(total+1, cnt, nr, nc, dir);
	
}
int main() {
	cin >> m >> n;
	visit[0][0] = 1;
	dfs(1, 0, 0, 0, 0);
	cout << res << endl;
	return 0;
}