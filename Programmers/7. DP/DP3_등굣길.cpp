#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int dist[100][100];
int solution(int m, int n, vector<vector<int>> puddles) {
	memset(dist, 0, sizeof(dist));
	for (int i = 0; i<puddles.size(); i++)
		dist[puddles[i][0]][puddles[i][1]] = -1; //�� ������
	dist[1][1] = 1;
	for (int i = 1; i <= m + 1; i++) {
		for (int j = 1; j <= n + 1; j++) {
			if (i == 1 && j == 1) continue;
			if (dist[i][j] == -1) {
				dist[i][j] = 0;
				continue;
			}
			dist[i][j] = (dist[i][j - 1] + dist[i - 1][j]) % 1000000007;
			//���� ���ʿ����� i,j �ε����� ���� �����ϴϱ�
		}
	}

	return dist[m][n];
}