#include<algorithm>
#include<iostream>
using namespace std;
/*DP����
dfs�� Ǯ�� �ð��ʰ� �߻�*/

int main() {
	int N, M;
	int map[1001][1001] = { 0, };
	int dp[1001][1001] = { 0, };
	int tmp[2][1001] = { 0, };
	cin >> N >> M;
	for (int i = 1; i <=N; i++) 
		for (int j = 1; j <=M; j++) 
			cin >> map[i][j];
	dp[1][1] = map[1][1];
	//ù���� ���������� �ۿ� �������̴ϱ� �̸� ���
	for (int i = 2; i <= M; i++) dp[1][i] += map[1][i] + dp[1][i - 1]; 


	for (int i = 2; i <= N; i++) {
		tmp[0][0] = dp[i - 1][1];//������ ������ ��
		for (int j = 1; j <= M; j++)//���ʿ��� ���������� ���� ���
			tmp[0][j] = max(tmp[0][j - 1], dp[i - 1][j]) + map[i][j];//���ʿ��� ���� ����, ������ �������� ��� ��
		
		tmp[1][M + 1] = dp[i - 1][M]; //������ ������ ��
		for (int j = M; j >= 1; j--)
			tmp[1][j] = max(tmp[1][j + 1], dp[i - 1][j]) + map[i][j];//�����ʿ��� ���� ����, ������ ���� ��츦 ��
		
		for (int j = 1; j <= M; j++)
			dp[i][j] = max(tmp[0][j], tmp[1][j]);
	}
	cout << dp[N][M];
	return 0;
}