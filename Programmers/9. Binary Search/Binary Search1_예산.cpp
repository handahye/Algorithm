#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0, N = budgets.size();
	sort(budgets.begin(), budgets.end());//�������� ����
	int left = 0, right = budgets[N - 1];
	while (left <= right) {
		int mid = (left + right) / 2;//(left+right)/2�� ���� ���Ѿ����� ����
		int sum = 0;
		for (int i = 0; i<N; i++)
			sum += min(budgets[i], mid);//���Ѿ׺��� ������ �װ�, ũ�� ���Ѿ�
		if (sum <= M) {//���Ѱ��� M���� ������
			answer = mid;
			left = mid + 1;//left�� ���Ѿ�+1�� ����
		}
		else right = mid - 1;//right�� ���Ѿ�-1�� ����

	}
	return answer;
}