#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
/*4530. ������ û�� �۾�*/
int T;
long long A, B;
long long cal(long long n) {//���
	long long tmp = n % 10;
	if (tmp > 4) tmp--; //4�̻��̸� 4�� �����ؼ� ���� ���ڴϱ� -1��
	if (n < 10) return tmp; //��������
	else return 9 * cal(n / 10) + tmp;
	//���� �ڸ� ������ 4�� ������ ���� �ִ� ������ ���
}
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> A >> B;
		long long a = (A < 0 ? -A : A);
		long long b = (B < 0 ? -B : B);
		long long res = 0;
		if (A < 0 && B>0) res = cal(a) + cal(b) - 1;
		else res = abs(cal(a) - cal(b));
		printf("#%d %lld\n", t, res);
	}
	return 0;
}