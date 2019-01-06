#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
/*4613. ���þ� ���� ���� ���*/
int T, N, M, minN;
char map[51][51];
int cal[51][3];
void dfs(int r, int cnt, int curType, int beforeType) {
	if (minN < cnt) return;
	if ((curType == 3 && beforeType == 1)|| (r==N-1 && curType==1)) return;
	if (r == N - 1) {
		minN = min(minN, cnt);
		return;
	}
	for (int type = curType; type <= 3; type++) {
		int change = M - cal[r][type - 1]; //�ٲ�� �ϴ� ����
		dfs(r + 1, cnt + change, type, curType);
	}
}
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(map, 0, sizeof(map));
		memset(cal, 0, sizeof(cal));
		minN = 987654321;
		int cnt = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			scanf("%s", map[i]);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//�� ù�ٰ� �������� ���� (W,R��)
				if (i == 0 && map[0][j] != 'W') cnt++;
				else if (i == N - 1 && map[N - 1][j] != 'R') cnt++;
				//�� �ึ�� W, B, R�� ��� �ִ��� ��������
				if (map[i][j] == 'W') cal[i][0]++;
				else if (map[i][j] == 'B') cal[i][1]++;
				else if (map[i][j] == 'R')cal[i][2]++;
			}
		}
		dfs(1, cnt, 1, 1); // r=1�� ���(1)���� �����ϴ� ���
		dfs(1, cnt, 2, 1); // r=1�� �Ķ���(2)���� �����ϴ� ���
						   //�������� ���� ������� �ʾƵ� ��	
		printf("#%d %d\n", t, minN);
	}
	return 0;
}