#include <math.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
#1057_��ʸ�Ʈ
1. 1~N������ ��ȣ�� ���� �ް� ���� ������ ��ȣ���� ��Ÿ
2. �̱� ����� ����, �� ��� ������
3. Ȧ�����̸� ������ ��ȣ�� �ڵ� ����
4. ���� ���忡�� �ٽ� ��ȣ �ű�
5. �� �� ���� ������ ��� ����
6. �����ΰ� ���Ѽ��� �� ���忡�� ����ϴ��� ����ϱ�
*/
int main() {
	int res = 1;
	int N, a, b;
	cin >> N >> a >> b;
	while (1) {
		if (a < b && a % 2 == 1 && a + 1 == b) break;
		else if (a > b && b % 2 == 1 && a - 1 == b) break;
		a = ceil(float(a) / 2.0);
		b = ceil(float(b) / 2.0);
		res++;
	}
	cout << res;
	return 0;
}