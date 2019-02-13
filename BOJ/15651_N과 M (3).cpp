#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
/*
BOJ_15651_N�� M (3)
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
- 1���� N���� �ڿ��� �߿��� M���� �� ����
- ���� ���� ���� �� ��� �ȴ�.
*/
int N, M;
vector<int> ans;
void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = 1 ; i <= N; i++) {
		ans.push_back(i);
		dfs(cnt + 1);
		ans.pop_back();
	}
}
int main() {
	cin >> N >> M;
	dfs(0);
	return 0;
}