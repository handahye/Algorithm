#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
using namespace std;
/*
BOJ_15664_N�� M (10)
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
- N���� �ڿ��� �߿��� M���� �� ����
- �� ������ �񳻸������̾�� �Ѵ�.
	: ���̰� K�� ���� A�� A1 �� A2 �� ... �� AK-1 �� AK�� �����ϸ�, �񳻸������̶�� �Ѵ�.
*/
int N, M;
vector<int> ans;
int arr[9];
bool chk[9];
set<vector<int>> s;
void dfs(int idx, int cnt) {
	if (cnt == M) {
		s.insert(ans);
		return;
	}
	for (int i = idx; i < N; i++) {
		if (!chk[i]) {
			chk[i] = true;
			ans.push_back(arr[i]);
			dfs(i, cnt + 1);
			ans.pop_back();
			chk[i] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	dfs(0, 0);
	for (auto iter : s) {
		for (auto k : iter) {
			printf("%d ", k);
		}
		printf("\n");
	}
	return 0;
}