#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
#2455_������ ����
1. 1~4���������� �뼱���� �����
2. Ÿ�ų� ������ ��� �� �ڵ����� �ν�
3. ��� -> ���������� ���� ���� ����� ���� ���� �� ���
4. ������ Ż ��, ���� ����� ��� ���� �� ������ Ž
*/
int main() {
	int res = 0, sum =0;
	for (int i = 0; i < 4; i++) {
		int minus, plus;
		cin >> minus >> plus;
		sum = sum - minus + plus;
		res = max(res, sum);
	}
	cout << res << endl;;
	return 0;
}