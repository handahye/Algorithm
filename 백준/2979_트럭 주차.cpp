#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<list>
using namespace std;
/*
#2979_Ʈ�� ����
1. Ʈ�� �� ���� ������ ����
2. Ʈ���� �����ϴµ� ��� ���
3. Ʈ���� ���� ���� ���� ��� ����
	3-1) �Ѵ� ���� -> 1�п� �� ��� A��
	3-2) �δ� ���� -> 1�п� �� ��� B��
	3-3) ���� ���� -> 1�п� �� ��� C��
4. A, B, C�� �־����� ��, ��������� �󸶸� �����ϴ��� 
*/
int main() {
	int a, b, c;
	int res = 0;
	vector<pair<int,int>> v;
	cin >> a >> b >> c;
	int cnt[101] = { 0, };
	for (int i = 0; i < 3; i++) {
		int s, e;
		cin >> s >> e;
		for (int j = s; j < e; j++)
			cnt[j] += 1;
	}
	for (int i = 0; i < 101; i++) {
		if (cnt[i] == 1) res += a;
		else if (cnt[i] == 2) res += b * 2;
		else if (cnt[i] == 3) res += c * 3;
	}
	
	cout << res;
	return 0;
}