#include <iostream>
#include <algorithm>
#include<vector>
#include <string>
using namespace std;
/*
#1120_���ڿ�
[����]
1. ���̰� N���� ���� ���ڿ� X�� Y�� ����
2. �� ���ڿ��� X�� Y�� ���̴� X[i]!=Y[i]�� i�� ���� 
3. �� ���ڿ� A�� B�� �־�����, A�� ���̴� B���� �۰ų� ����
4. �������� ���� A�� ���̳� �ڿ� �ƹ� ���ĺ� �߰� ����
5. A�� B�� ���̰� �����鼭 A�� B�� ���̸� �ּҷ� �ϱ�

[���ٹ��]
1. ó���� dfs�� �����ߴٰ� �ð��ʰ� ����
*/
int main() {
	string a, b;
	int cnt = 0, ans = 987654321;
	cin >> a >> b;
	for (int i = 0; i <= b.size() - a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (a[j] != b[j + i]) ++cnt;
		}
		ans = min(cnt, ans);
		cnt = 0;
	}
	cout << ans << endl;
	return 0;
}