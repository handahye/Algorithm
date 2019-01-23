#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include<iostream>
using namespace std;
/*bfs - priorty queue*/
int visit[101];
vector<pair<int, int>> island[101];
void init() {
	memset(visit, 0, sizeof(visit));
	island->clear();
}
int bfs() {
	int dist = 0;
	priority_queue<pair<int, int>> pq;//cost, ��߼�
	pq.push({ 0,0 });
	while (!pq.empty()) {
		int u = pq.top().first;
		int u = pq.top().second;
		int cost1 = -pq.top().first;
		pq.pop();

		if (visit[u]) continue;
		visit[u] = 1;
		dist += cost1;

		for (int i = 0; i < island[u].size(); i++) {
			int v = island[u][i].first;
			int cost2 = island[u][i].second;
			if (!visit[v]) pq.push({ -cost2, v });
		}
	}
	return dist;
}
int solution(int n, vector<vector<int>> &costs) {
	int answer = 0;
	init();
	for (int i = 0; i<costs.size(); i++) {
		int u = costs[i][0];
		int v = costs[i][1];
		island[u].push_back({ v,costs[i][2] });
		island[v].push_back({ u,costs[i][2] });
	}
	return bfs();

}

/*dfs�� Ǭ ��.. �¿�Ʋ...*/
int minN = 987654321, N;
void dfs(int idx, int sum, int cnt) {
	if (cnt == N) {//��� ���� �� �湮�ϸ�
		minN = min(minN, sum);
		return;
	}
	//idx��° ������ �� �� �ִ� ��� ����
	for (int i = 0; i<island[idx].size(); i++) {
		int next = island[idx][i].first;
		int cost = island[idx][i].second;
		//���� �湮���� ���� ���̰�, ���� ���� ������ ������ �ͺ��� ���� ��쿡��
		if (!visit[next] && sum + cost <= minN) {
			visit[next] = 1;
			dfs(next, sum + cost, cnt + 1);
			visit[next] = 0;
		}
	}
}
void init() {
	minN = 987654321;
	memset(visit, 0, sizeof(visit));
	island->clear();
}
int solution(int n, vector<vector<int>> costs) {
	init();
	for (int i = 0; i<costs.size(); i++) {
		int u = costs[i][0];
		int v = costs[i][1];
		island[u].push_back({ v,costs[i][2] });
		island[v].push_back({ u,costs[i][2] });
	}
	N = n;
	for (int i = 0; i<n; i++) {//0���� �������� ��, 1�� �������� ��, ..n-1�� �������� ��
		visit[i] = 1;//�湮 üũ
		dfs(i, 0, 1);
		visit[i] = 0;
	}
	return minN;
}
