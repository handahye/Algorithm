#include<iostream>
#include<algorithm>
using namespace std;
/*5603. [Professional] ���ʴ���*/
//�켱 ���ʴ��� ũ�� ������ ����
//���� ũ�Ⱑ ū �ֺ��� ���� ���� ������ ����ϴ� �������
int T,N;
int S[10001];
int main(){
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int cnt = 0, total = 0, avg =0;
		int chk[10001] = { 0, };
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> S[i];
			total += S[i];
		}
		sort(S, S + N);//����
		avg = total / N;
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (S[i] <= avg)break;//������ ���ʰ� ������ �������� ū ���ʷ� �Ѿ
				if (chk[j]) continue; //�̹� ���ʰ� �� �Ű��� ���
				if (S[j] == avg) {//�ű��� �ʾƵ� �Ǵ� ���
					chk[j] = 1;
					continue;
				} 
				if (S[j] < avg) {
					int tmp = avg - S[j]; //�ʿ��� Ƚ��
						if (avg <= S[i] - tmp) { //�ѹ��� �� �� �ִ� ���
							cnt += tmp;
							S[j] += tmp, S[i] -= tmp;
							chk[j] = 1;
						}
						else if (avg > S[i] - tmp) {//�ѹ��� �� �� ���� ���
							cnt += (S[i] - avg);
							S[j] += (S[i] - avg);
							S[i] -= (S[i] - avg);
							break;
						}
				}
			}
		}
		printf("#%d %d\n", t, cnt);
	}
	return 0;
}