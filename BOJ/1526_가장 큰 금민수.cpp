#include <string>
#include <iostream>
#include <algorithm>
#include<vector>
#include<list>
using namespace std;
/*
#1526_���� ū �ݹμ�
1. �����̴� 4�� 7�� �����ϰ�, ������ ���ڴ� �Ⱦ���
2. �ݹμ� = 4�� 7�θ� �̷���� ��
3. N���� �۰ų� ���� �ݹμ� �� ���� ū�� ����ϱ�
*/
int res = 0;
void dfs(int num, int n) {
	if (num > n) return;
	res = max(res, num);
	dfs(num * 10 + 4, n);
	dfs(num * 10 + 7, n);
}
int main() {
	int n;
	cin >> n;
	dfs(0, n);
	cout << res;
	return 0;
}