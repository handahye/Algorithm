#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
/*
BOJ_15650_N�� M (2)
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
- 1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
- �� ������ ���������̾�� �Ѵ�.
*/
bool visit[10];
int N, M;
vector<int> ans;
void dfs(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = idx+1 ; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			ans.push_back(i);
			dfs(i, cnt + 1);
			ans.pop_back();
			visit[i] = false;
		}

	}
}
int main() {
	cin >> N >> M;
	dfs(0, 0);
	return 0;
}