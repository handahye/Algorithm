#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<iostream>
using namespace std;
/*
#11077_����0
1. ������ �� N����, ������ ������ �ſ� ���� ����
2. ������ ����ؼ� ��ġ�� �� K�� �����
3. �ʿ��� ���� ���� �ּڰ� ���ϱ�
*/
bool cmp(int &a, int &b) {
	return a > b;
}
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	int j=0;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > K) break;
		A[i] = tmp;
		j++;
	}
	sort(A.begin(), A.end(), cmp);
	int sum = K, cnt = 0;
	int idx = 0;
	while (1) {
		if (sum == 0) break;
		sum -= A[idx];
		if (sum < 0) {
			sum += A[idx];
			idx++;
			continue;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}