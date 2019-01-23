#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int score[2002][2002], maxScore, n;
void dfs(int i, int j, int curScore, vector<int> left, vector<int> right) {
	if ((curScore <= score[i][j]) || (i == n + 1 || j == n + 1)) return;
	if (curScore>score[i][j]) {//i��° ���� ī��, j��° ������ ī�� ��ġ�� ��, ���� ū ���� �Ǵ� score
		score[i][j] = curScore;
		maxScore = max(curScore, maxScore);
	}
	if (left[i]>right[j]) { //������ ī�尡 �� ������
		dfs(i, j + 1, score[i][j] + right[j], left, right);//������ ī�� ����
	}
	else {
		dfs(i + 1, j, curScore, left, right);//���� ī�� ������
		dfs(i + 1, j + 1, curScore, left, right);//���� ������ ī�� ������
	}
}
int solution(vector<int> left, vector<int> right) {
	maxScore = 0;
	n = left.size();
	memset(score, -1, sizeof(score));
	dfs(0, 0, 0, left, right);
	return maxScore;
}