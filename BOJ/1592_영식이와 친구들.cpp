#include <iostream>
#include <algorithm>
#include<vector>
#include <string>
using namespace std;
/*
#1592_�����̿� ģ����
1. ���� �ְ� �����鼭 ���� ���� Ƚ���� M�̸� ������ ����
2. ���� ���� �� ���� Ƚ����
1) Ȧ���� �ݽð� �������� L��° ������� ����
2) ¦���� �ð� �������� L��° ������� ����
*/
int main() {
	int res = 0;
	int N, M, L;
	cin >> N >> M >> L;
	int chk[1002] = { 0, };
	int p = 1;
	while (1) {
		if (chk[p] == M) break;
		if (chk[p] % 2 == 0) {
			p = (p + L) % N;
			if (p == 0) p = N;
			chk[p] += 1;
		}
		else {
			if (p - L <= 0) p = p - L + N;
			else p = p - L;
			chk[p] += 1;
		}
		res++;
	}
	cout << res -1<< endl;
	return 0;
}