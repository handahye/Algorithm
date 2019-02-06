#include <queue>
#include <vector>
#include <map>
#include <functional>
using namespace std;
int solution(int n, vector<vector<int>> edge) {
	vector<int> node[20002];
	int visit[20002] = { 0, };
	//����� ���� üũ
	for (int i = 0; i<edge.size(); i++) {
		int u = edge[i][0];
		int v = edge[i][1];
		node[u].push_back(v);
		node[v].push_back(u);
	}
	queue<int> q; //��� ��ȣ
	q.push(1);
	visit[1] = 1; //1�� ��忡��
	while (!q.empty()) {
		int u = q.front();//���� ��� ��ȣ
		q.pop();

		for (int i = 0; i<node[u].size(); i++) {//���� ��忡�� ����� ����
			int next = node[u][i];
			if (visit[next] == 0) {//���� �湮���� ���� ���鸸 ť�� �߰�
				visit[next] = visit[u] + 1;//�湮�� �� �ִ� ����� ���� +1�� ����
				q.push(next);
			}
		}
	}
	int answer = 0, maxN = -98764321;
	for (int i = 1; i <= n; i++) maxN = max(maxN, visit[i]); //�ִ� ���� �� ���ϱ�
	for (int i = 1; i <= n; i++) if (visit[i] == maxN) answer++;//�ִ� ���� ���� ���� ��� ���� ���ϱ�
	return answer;
}
