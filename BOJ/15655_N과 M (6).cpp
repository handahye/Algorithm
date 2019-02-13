#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
/*
BOJ_15655_N�� M (6)
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
N���� �ڿ����� ��� �ٸ� ���̴�.
- N���� �ڿ��� �߿��� M���� �� ����
- �� ������ ���������̾�� �Ѵ�.
*/
int N, M;
vector<int> ans;
int arr[9];
bool visit[9];
void dfs(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = idx+1; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			ans.push_back(arr[i]);
			dfs(i, cnt + 1);
			ans.pop_back();
			visit[i] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		visit[i] = true;
		ans.push_back(arr[i]);
		dfs(i, 1);
		ans.pop_back();
		visit[i] = false;
	}
	return 0;
}