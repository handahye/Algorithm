#include<iostream>
using namespace std;
/*4698. �׳׽��� Ư���� �Ҽ�*/
int T;
bool res[1000001] = { 0, };
int map[1000001][10] = { 0, };
int main(){
	cin >> T;
	//�Ҽ� ���ϴ� �κ�
	for (int i = 2; i < 1000001; i++) {
		if (res[i])continue;
		for (int j = 2; j*i < 1000001; j++) {
			res[j*i] = 1;
		}
	}
	//2~1000000������ ���ڰ� �� �ڸ����� � ���ڸ� ������ �ִ���
	for (int i = 2; i < 1000001; i++) {
		if (!res[i]) {
			int tmp = i;
			while (tmp > 0) {
				int n = tmp % 10;
				tmp /= 10;
				map[i][n]++;
			}
		}
	}
	/*�Ǽ��� �κ�: �� ���� �Ҽ� ���ϴ� �κ��� �� for������ �־ �ڵ带 ®�ٰ� �ð� �ʰ��� �߻��ߴ�*/
	for(int t = 1; t <= T; t++) {
		int D, A, B;
		cin >> D >> A >> B;
		int cnt = 0;
		for (int i = A; i <= B; i++)
			if (map[i][D] > 0) cnt++;

		printf("#%d %d\n", t, cnt);
	}
	return 0;
}