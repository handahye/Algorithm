#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//����, �Ʒ� �� ������ ��� ����
long long solution(int N) {
	long long r, c;
	int cnt = 2;
	r = 1;
	c = 2;
	while (1) {
		if (cnt == N) return (r * 2 + c * 2);
		if (cnt % 2 == 0) r = r + c;
		else c = c + r;
		cnt++;
	}
}