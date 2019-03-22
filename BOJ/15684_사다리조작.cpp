#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int H, N, M;
int map[32][12];
bool visit[32][12];
int res;
int ladder(int r, int c) {
	if (r > H) {
		return c;
	}
	if (c + 1 <= N && map[r][c] == 1 && map[r][c + 1] == 2 &&!visit[r][c+1]) {
		visit[r][c + 1] = true;
		ladder(r, c + 1);
	}
	else if (c - 1 >= 1 && map[r][c] == 2 && map[r][c - 1] == 1 &&!visit[r][c-1]) {
		visit[r][c - 1] = true;
		ladder(r, c - 1);
	}
	else {
		visit[r + 1][c] = true;
		ladder(r + 1, c);
	}
}
bool chk() {
	for (int i = 1; i <= N; i++) {
		memset(visit, false, sizeof(visit));
		visit[1][i] = true;
		int num = ladder(1, i); 
		if (num != i) return false;
	}
	return true;
}
void dfs(int cnt, int h) {
	if (cnt > 3||res<cnt) return; //4�� �̻� ���ų� ���� res������ cnt�� Ŀ���� ���ʿ� ����! 
	if (chk()) { //��ٸ� �ϳ� ���������� üũ��
		res = min(res, cnt); //���� ������ ���� res�� ����
		return;
	}
	for (int i = h; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (map[i][j] == 0 && map[i][j + 1] == 0) { //��ٸ��� ���������� ���� ����
				map[i][j] = 1;
				map[i][j + 1] = 2;
				dfs(cnt + 1, i); 
				map[i][j] = 0;
				map[i][j + 1] = 0;
			}
		}
	}
}
int main() {
	res = 987654321;
	scanf("%d%d%d", &N, &M, &H);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		map[a][b] = 1;
		map[a][b + 1] = 2;
	}
	dfs(0,1);
	if (res == 987654321) printf("-1\n");
	else printf("%d\n",res);
	return 0;
}
