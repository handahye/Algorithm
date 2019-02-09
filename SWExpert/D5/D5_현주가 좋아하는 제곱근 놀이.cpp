#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
/*
D5_���ְ� �����ϴ� ������ ����
*/
long long res;
bool chk;
void dfs(long long cnt, long long num) {
	if (chk) return;
	if (res < cnt) return;
	if (num == 1) {
		res = min(res, cnt + 1);
		chk = true;
		return;
	}
	if (num == 2) {
		res = min(res, cnt);
		chk = true;
		return;
	}
	long long number = pow((long long)sqrt(num), 2) - num;
	if (number == 0) dfs(cnt + 1, (long long)sqrt(num)); //���� ���� ���������� üũ
	else {
		int count = pow((long long)sqrt(num) + 1, 2) - num; //�������� �ƴϸ� ���� ����� �������� ã��
		dfs(cnt + count + 1, (long long)sqrt(num) + 1);//������ �������� ������� ������ ��ŭ + ��Ʈ���� ��
	}

}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		res = 999999999999;
		chk = false;
		long long N;
		cin >> N;
		dfs(0, N);
		cout << "#" << t << " " << res << endl;
	}
	return 0;
}