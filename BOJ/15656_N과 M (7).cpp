#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
/*
BOJ_15656_N�� M (7)
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
N���� �ڿ����� ��� �ٸ� ���̴�.
- N���� �ڿ��� �߿��� M���� �� ����
- ���� ���� ���� �� ��� �ȴ�.
*/
int N, M;
vector<int> ans;
int arr[9];
void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		printf("\n");
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
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	dfs(0);
	return 0;
}