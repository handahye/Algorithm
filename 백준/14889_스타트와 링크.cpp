#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
#14889_��ŸƮ�� ��ũ
[����]
1. Sij + Sji�� i���� j�� ����� ���� ��, ���� �������� �ɷ�ġ
2. Sij�� Sji�� �ٸ� �� ����
3. �� �� �ɷ�ġ ������ �ּڰ��� ���ض�

[���ٹ��]
1. �ΰ��� ���� ���� �� �ִ� ��� ��츦 ����
2. ������ ���� �� �� �ɷ����̰� ���� ���� ��츦 ����
*/

int map[21][21];
int visit[21];
int N, minN=987654321;
int calScore(vector<int> &v) {//�ɷ�ġ ���ϱ�
	int sum = 0;
	for (int i = 0; i < v.size(); i++) 
		for (int j = 0; j < v.size(); j++) 
			sum += map[v[i]][v[j]];
	return sum;
}
int res() {
	vector<int> start, link; 
	for (int i = 0; i < N; i++) {//start�� link �� ����
		if (visit[i]) start.push_back(i);
		else link.push_back(i);
	}
	return abs(calScore(start) - calScore(link));	
}
void dfs(int idx, int cnt) {
	if(cnt == N / 2) {
		minN = min(minN,res());
		return;
	}
	for (int i = idx + 1; i < N; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			dfs(i, cnt + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> map[i][j];

	visit[0] = 1;
	dfs(0, 1);

	printf("%d", minN);
	return 0;
}