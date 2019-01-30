#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
#1931_ȸ�ǽǹ���
1. �Ѱ��� ȸ�ǽ� -> N���� ȸ�ǿ� ���ؼ� ���ǥ
2. ȸ�ǿ� ���ؼ� ����, �� �ð� �־���
3. ȸ�ǰ� ��ġ�� �ʰ� ��밡���� �ִ� ȸ�� ã��
4. �� ȸ�ǰ� ������ ���ÿ� ���� ȸ�� ���� ����
5. ���� �ð� = ������ �ð� ����(�������� ���� ������ ���)

1) ���� ���� ������ ȸ�� ���� ��� 
2) ���� �ð��� ���� �� ���� �ð��� ���� ������� 
*/
struct que{
	int start;
	int end;
};
bool operator<(que q1, que q2) {
	if (q1.end != q2.end) 
		return q1.end > q2.end;
	return q1.start > q2.start;
}
int main() {
	int n;
	priority_queue<que> pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		pq.push({ s,e });
	}
	int endPoint = -1;
	int res = 0;
	
	while (!pq.empty()) {
		int start = pq.top().start;
		int end = pq.top().end;
		pq.pop();

		if (start >= endPoint) {
			res++;
			endPoint = end;
		}
	}
	cout << res << endl;;
	return 0;
}