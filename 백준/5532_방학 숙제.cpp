#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
#5532_���� ����
[����]
1. ������ �� L��, ���� B������, ���� A������ Ǯ��ߵ�
2. ����̴� �Ϸ翡 ���� �ִ� C������, ���� �ִ� D������ Ǯ�� ����
3. ���� �� ���� ���ϰ� �� �� �ִ� �ִ� ���� �� ���ϱ�
*/
int main() {
	int res = 0;
	int L, A, B, C, D;
	cin >> L >> A >> B>>C>>D;
	res = L;
	int a = ceil(float(A) / float(C));
	int b = ceil(float(B) / float(D));
	printf("%d", res-(max(a,b)));
	return 0;
}