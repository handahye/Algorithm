#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int N, B, C;
int A[1000001];
int main() {
	long long cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	scanf("%d%d", &B, &C);
	for (int i = 0; i < N; i++) {
		A[i] -= B; //�� ������ ������ ������ �� ��
		cnt++;
		if (A[i] > 0) { //���� �����ؾ� �� ������ ���� ���� ���
			if (A[i] % C == 0) cnt += (A[i] / C);
			else cnt += (A[i] / C) + 1;
		} //�ʿ��� �� ������ ��ŭ ������
	}
	printf("%lld", cnt);
	return 0;
}