#include <iostream>
#include<string>
#include<queue>
#include<string.h>
using namespace std;
/*
BOJ_14391_���� ����
*/
int visit[5][5];
int map[5][5];
int N, M;
int maxN;
void chk() {
	//������ ���: visit 1
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		for (int j = 0; j < M; j++) {
			if (visit[i][j]) { //�����ؼ� ��� 1�� ������ ���
				tmp *= 10; //�ڸ���
				tmp += map[i][j];
			}
			else { //0�� ���ͼ� ������ ���
				sum += tmp; //������� ���Ѱ͸� 
				tmp = 0;
			}
		}
		sum += tmp;
	}
	//������ ���: visit 0
	for (int i = 0; i < M; i++) {
		int tmp = 0;
		for (int j = 0; j < N; j++) {
			if (!visit[j][i]) {
				tmp *= 10;
				tmp += map[j][i];
			}
			else {
				sum += tmp;
				tmp = 0;
			}
		}
		sum += tmp;
	}
	maxN = max(maxN, sum);
}
void dfs(int r, int c) {
	if (r == N) {
		chk();
		return;
	}
	if (c == M) r = r + 1, c = 0;

	visit[r][c] = 1;
	dfs(r, c + 1);

	visit[r][c] = 0;
	dfs(r, c + 1);

}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);

	maxN = -987654321;
	dfs(0, 0);
	cout << maxN;
	return 0;
}