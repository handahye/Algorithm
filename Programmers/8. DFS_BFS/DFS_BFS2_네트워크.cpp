#include <string.h>
#include <vector>
/*
1. i��(0~n-1)�� ����� ��ǻ�� üũ
2. ����� ��ǻ�� �湮
3. ��� �湮�� ��ǻ�Ϳ��� �� ����Ǵ� ��ǻ�Ͱ� ������ �湮
4. ���ᰡ���� ��� ��ǻ�͸� �湮�� ��� answer++����
5. 1�� ���ư��� ���� �湮���� ���� ��ǻ�͸� �������� �� üũ
*/
using namespace std;
int visit[201];
int curIdx = 0;
void dfs(int idx, vector<vector<int>> computers) {
	for (int j = 0; j<computers[idx].size(); j++) {
		if (idx == j) continue;
		if (computers[idx][j] == 1 && !visit[j]) {//���� ��ǻ�Ϳ��� ����Ǿ� �ְ�, ���� �湮���� ���� ��ǻ�͵� ��
			visit[j] = 1;//�湮üũ
			dfs(j, computers);
		}
	}
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i<n;i++) { //0~n�������� ��ǻ�� �� ���� �湮���� ���� ��ǻ�Ͱ� ����
		if (!visit[i]) {
			visit[i] = 1;
			dfs(i, computers);
			answer++;//��Ʈ��ũ �� ����
		}
	}
	return answer;
}