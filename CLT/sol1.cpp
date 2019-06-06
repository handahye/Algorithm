#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int cal(string s1, string s2) {
	int maxN = 0;
	int s1Len = s1.size()-1; //s1�� ����
	for (int i = s2.size()-1; i >=0; i--) {
		bool flag = false;
		if (s2[i] == s1[s1Len]) { //���� s2�� ����Ű�� ���ĺ��� s1�� ������ ���ĺ��� ������
			int cnt = 1;
			for (int j = i-1, k = s1Len-1; j >= 0; j--, k--) { //�� �յ� ���ĺ��� ��ġ���� Ȯ��
				if (s2[j] != s1[k] || k<0) { //���ĺ��� �ٸ� ��� or s1: bc s2: abc �̷� ��� s1�� �տ� ���̻� Ȯ���Ұ� ����(k<0)
					flag = true;
					break;
				}
				else cnt++; //������ ��ġ�� �κ� ����
			}
			if (!flag) maxN = max(cnt, maxN); //��ġ�°� ������ ���� ū���� maxN�� ����
		}
	}
	return maxN;
}
int main(){
	string s1 = "ababc", s2 = "abcdab";
	//s1->s2 ������ ���ΰͰ� s2->s1 ������ ���ΰ� �߿� ������ ���ڰ� �� ���� �� res�� ����
	int res = max(cal(s1, s2), cal(s2, s1));
	printf("%d", s1.size() + s2.size() - res); //s1�� ����+s2�� ���� - �������� ���ĺ���
	return 0;
}