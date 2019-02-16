#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
/*
D5_�������
:TSP����
*/
int map[15][15];
int visit[15];
int N;
int sr, sc, er, ec;
int minN = 987654321;
vector<pair<int, int>> v;
void dfs(int cur, int cnt, int sum) {
	if (cnt == v.size()) {//������ ��� �湮�� ���
		int tmp = abs(v[cur].first - er) + abs(v[cur].second - ec); //������ �� ��ġ���� �������� �Ÿ� ���
		minN = min(minN, sum+tmp);//������ ���� ���� ��������� �̵��Ÿ��� ���ؼ� �ּڰ��� minN�� �����ص� 
		return;
	}
	for (int next = 0; next < v.size(); next++) {
		if (!visit[next] && next!=cur) { //���� �湮���� ���� �մ��� ���
			if (sum + map[cur][next] < minN) { //������� �̵��ؿ� �Ÿ� + ���� �̵��ؾ� �ϴ� �Ÿ��� ���� �����ص״� minN������ ���� ��쿡��
				visit[next] = 1;//�湮üũ
				dfs(next, cnt + 1, sum + map[cur][next]);
				visit[next] = 0;
			}
		}
	}
}
void init() {
	//i�� j�� �Ÿ� �̸� ����ؼ� ����
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i == j) map[i][j] = 0;
			else map[i][j] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
		}
	}
	for (int i = 0; i < 15;i++) visit[i] = 0;
	minN = 987654321;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		cin >> sr >> sc;
		cin >> er >> ec;
		v.clear();
		v.push_back({ sr,sc }); //ȸ��� �մԵ��� ��ǥ�� ��� vector�� ����
		for (int i = 0; i < N; i++) {
			int r, c;
			cin >> r >> c;
			v.push_back({ r,c });
		}
		init();

		visit[0] = 1;
		dfs(0, 1, 0);
		printf("#%d %d\n", t, minN);
	}

	return 0;
}