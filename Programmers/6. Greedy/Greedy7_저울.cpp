#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> weight) {
	int sum = 1;//���� ���� ���� ���԰� 1�̴ϱ� �� ó�� ���� �� �ִ� ���Դ� 1
	sort(weight.begin(), weight.end());
	for (int i = 0; i<weight.size(); i++) {
		if (sum < weight[i]) break;//���� 1~sum������ ���Ը� ���� �� �ִµ� �ִ� ������ sum���� ���� ���԰� Ŀ���� �ȵ�
		num += weight[i]; //���� sum�� ���� ���Ը� �߰��� 
	}
	return num;
}