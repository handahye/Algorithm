#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
#1094_�����
1. 64cm�� ����� -> �߶� Ǯ�� �ٿ� ���̰� Xcm ����� ����
2. �����̰� ������ �ִ� ������ ���̸� ��� ���� ���� X���� ũ��
2-1) ������ �ִ� ���� �� ���� ª�� �� �������� �ڸ�
2-2) ������ �ڸ� ������ ���� �� �ϳ��� ������ �����ִ� ������ ������ ���� X���� ũ�ų� ������
������ �ڸ� ������ ���� �� �ϳ��� �� ����
3. �����ִ� ��� ���븦 Ǯ�� �ٿ� Xcm�� ����
4. ��� ���븦 Ǯ�� ���̴���?
*/
int main() {
	int N = 64;
	int n;
	cin >> n;
	int sum = 0, res = 0;
	while (1) {
		if (N == n) break;
		if (N > n) {
			N = N / 2;
			continue;
		}
		sum += N;
		if (sum > n) {
			sum -= N;
			N = N / 2;
			continue;
		}
		res++;
	}
	cout << res;
	return 0;
}