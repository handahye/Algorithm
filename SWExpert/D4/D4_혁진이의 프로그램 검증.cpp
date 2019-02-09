#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
using namespace std;
/*
D4_�������� ���α׷� ����
1. ���� ���� �̵��� 2���� ������ �ٱ����� �̵��ϴ� �����̸�, �ݴ��� �ִ� ��ġ�� �̵��Ѵ�.
2. ����������� �޸𸮰� �� �ϳ� ������, 0���� 15������ ������ �ϳ� ������ �� �ִ�. ���� ó������ 0�� ����Ǿ� �ִ�.
3. �־��� ���α׷��� ������ �� ������ ��YES���� ����ϰ�, �ƴϸ� ��NO���� ����Ѵ�.
*/
char map[21][21];
int visit[4][16][21][21]; //dir, num, r, c <- �迭 [4][15][20][20]���� �����ߴٰ� ��� Ʋ��^-^.. 
int R, C;
bool ans;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };
void chkNum(int &r, int &c) {
	if (r >= R) r = 0;
	if (c >= C) c = 0;
	if (r < 0) r = R - 1;
	if (c < 0) c = C - 1;
}
void dfs(int r, int c, int num, int dir) {
	if (ans) return;
	if (map[r][c] == '@') {
		ans = true;
		return;
	}
	else if (map[r][c] >= '0' && map[r][c] <= '9') num = map[r][c] - '0';
	else if (map[r][c] == '>') dir = 0;
	else if (map[r][c] == '<') dir = 1;
	else if (map[r][c] == '^') dir = 2;
	else if (map[r][c] == 'v') dir = 3;
	else if (map[r][c] == '_') num == 0 ? dir = 0 : dir = 1;
	else if (map[r][c] == '|') num == 0 ? dir = 3 : dir = 2;
	else if (map[r][c] == '-') num == 0 ? num = 15 : num -= 1;
	else if (map[r][c] == '+') num == 15 ? num = 0 : num += 1;
	if (map[r][c] == '?') {
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			chkNum(nr, nc);
			if (visit[d][num][nr][nc]) continue;
			visit[d][num][nr][nc] = 1;
			dfs(nr, nc, num, d);
		}
	}
	else {
		int nr = r + dr[dir], nc = c + dc[dir];
		chkNum(nr, nc);
		if (visit[dir][num][nr][nc]) return;
		visit[dir][num][nr][nc] = 1;
		dfs(nr, nc, num, dir);
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans = false;
		memset(visit, 0, sizeof(visit));
		cin >> R >> C;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> map[i][j];
		dfs(0, 0, 0, 0);
		if (ans)
			cout << "#" << t << " " << "YES" << endl;
		else
			cout << "#" << t << " " << "NO" << endl;
	}
	return 0;
}