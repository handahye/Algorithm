#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
using namespace std;
int visit[11];
int N, ans;
bool chk(int i) {
	for (int j = 0; j < i; j++) {//0���� ���� ����� 
		if (visit[j] == visit[i] || abs(visit[i] - visit[j]) == (i - j)) 
			return false;
	}
	return true;
}
void dfs(int cnt) {
	if (cnt == N) { //N���� ��� �� ���
		ans += 1;
		return;
	}
	for (int i = 0; i < N; i++) { //������ġ ã��
		visit[cnt] = i; 
		if (chk(cnt)) //���� �ڸ��� ���� ���� �� �ִ���
			dfs(cnt + 1);
	}
}
int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(visit, 0, sizeof(visit));
		cin >> N;
		ans = 0;
		dfs(0);
		cout << "#"<<t<<" " <<ans << endl;
	}
	return 0;
}