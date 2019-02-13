#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
using namespace std;
/*
BOJ_15664_N�� M (11)
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
- N���� �ڿ��� �߿��� M���� �� ����
- ���� ���� ���� �� ��� �ȴ�.
*/
int N, M;
vector<int> ans;
int arr[9];
set<vector<int>> s;
void dfs(int cnt) {
	if (cnt == M) {
		s.insert(ans);
		return;
	}
	for (int i = 0; i < N; i++) {
		ans.push_back(arr[i]);
		dfs(cnt + 1);
		ans.pop_back();
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	dfs(0);
	for (auto iter : s) {
		for (auto k : iter) {
			printf("%d ", k);
		}
		printf("\n");
	}
	return 0;
}