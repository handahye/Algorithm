#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<list>
using namespace std;
/*
#1021_ȸ���ϴ� ť
1. ù ��° ���Ҹ� �̾Ƴ���. �� ������ �����ϸ�, ���� ť�� ���Ұ� a1, ..., ak�̾��� ���� a2, ..., ak�� ���� �ȴ�.
2. �������� �� ĭ �̵���Ų��. �� ������ �����ϸ�, a1, ..., ak�� a2, ..., ak, a1�� �ȴ�.
3. ���������� �� ĭ �̵���Ų��. �� ������ �����ϸ�, a1, ..., ak�� ak, a1, ..., ak-1�� �ȴ�.
4. ���Ҹ� �־��� ������� �̾Ƴ��µ� ��� 2��, 3�� ������ �ּڰ� ���
*/
int main() {
	int res = 0;
	int left, right;
	int n, m;
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	list<int> num;
	for (int i = 1; i <= n; i++) num.push_back(i);
	for (int i = 0; i < v.size(); i++) {
		int cur = num.front();
		if (cur == v[i]) {
			num.pop_front();
			continue;
		}
		else {
			auto iter = find(num.begin(), num.end(), v[i]);
			int left = distance(num.begin(), iter);
			int right = distance(iter, num.end());
			if (left <= right) {
				res += left;
				while (left--) {
					int f = num.front();
					num.pop_front();
					num.push_back(f);
				}
				num.pop_front();
			}
			else {
				res += right;
				while (right--) {
					int b = num.back();
					num.pop_back();
					num.push_front(b);
				}
				num.pop_front();
			}
		}
	}
	cout << res;
	return 0;
}