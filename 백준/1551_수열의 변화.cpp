#include <string>
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
#1551_������ ��ȭ
1. ũ�Ⱑ N�� ���� A�� �־������� ��, ������ �� ������ ���̸� �̿���
ũ�Ⱑ N-1 ���� B�� ����
2. B[i] = A[i+1]-A[i]
3. A�� �־����� ��, �����̰� ���� ����� K��� ���� �� ������ ���� ���ϱ�
*/
int main() {
	int A[21] = { 0, };
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		char tmp;
		if (i == n - 1) cin >> A[i];
		else cin >> A[i] >> tmp;
	}
	int cnt = k;
	while (cnt--) {
		for (int i = 0; i < n - 1; i++)
			A[i] = A[i + 1] - A[i];
	}
	for (int i = 0; i < n - k - 1; i++) cout << A[i]<<",";
	cout << A[n - k - 1];
	return 0;
}