#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<list>
using namespace std;
/*
#1547_��
1. 1���ſ� �� �ϳ� �ֱ�
2. �� ���� ����, �� ��ġ�� �ٲ�
3. M�� ���� ��ġ �ٲ� �� ���� ���� ����ִ� �� ��ȣ ã��
*/
int main() {
	int res = 1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a == res) res = b;
		else if (b == res) res = a;
	}
	cout << res;
	return 0;
}