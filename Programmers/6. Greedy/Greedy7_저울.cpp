#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> &weight) {
	int num = 1;
	sort(weight.begin(), weight.end());
	for (int i = 0; i<weight.size(); i++) {
		if (num<weight[i]) break;//�߰��Ϸ��� ���� ���԰� ������� ���� �� �ִ� ���Ժ��� Ŀ���� ���
		num += weight[i]; //weight[i]�� �ϳ��� �߰��ϴ� ��� 1~num������ ���Ը� ���� �� ����
	}
	return num;
}
