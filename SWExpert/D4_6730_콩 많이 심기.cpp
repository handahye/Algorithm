#include <iostream>
#include<string.h>
using namespace std;
/*�迭 ũ�⶧���� ��� 1�� Ʋ�ȴ� ,, */
int map[1005][1005];
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int  N, M;
		int res = 0;
		cin >> N >> M;
		//�迭 ���鼭 ���� 2�� �κ� ����
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) {
					map[i + 2][j] = 1;
					map[i][j + 2] = 1;
				}
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] == 0) res++;
		printf("#%d %d\n", t, res);
	}
	return 0;
}