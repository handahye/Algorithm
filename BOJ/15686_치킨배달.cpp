#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int visit[14];
int dist[102][14];
vector <pair<int,int>> chicken, home;
int minN = 987654321;
int n, m;
int calDist() {
	int res = 0;
	for (int i = 0; i < home.size(); i++) {
		int d = 987654321;
		//�� ������ m�� ���õ� �� �� ���� ����� ġŲ�� ã��
		for (int j = 0; j < chicken.size(); j++) {
			if (visit[j]) {
				d = min(d, dist[i][j]);
			}
		}
		res += d;
	}
	return res;
}
void dfs(int idx, int cnt) {
	if (cnt == m) { //m���� ��� ���� ���
		minN = min(minN, calDist());
		return;
	}
	for (int i = idx + 1; i < chicken.size(); i++) {
		if (!visit[i]) {
			visit[i] = 1;
			dfs(i, cnt + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			if (num == 2) chicken.push_back({ i,j });
			else if (num == 1) home.push_back({ i,j });
		}
	}
	for (int i = 0; i < home.size();i++) { //������ ġŲ������ ���� �Ÿ� ���س��� 
		for (int j = 0; j < chicken.size(); j++) {
			dist[i][j] = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
		}
	}
	for (int i = 0; i < chicken.size();i++) { //M���� ġŲ�� �̱�
		visit[i] = 1;
		dfs(i, 1);
		visit[i] = 0;
	}
	printf("%d", minN);
	cin >> n;
	return 0;
}