#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	sort(times.begin(), times.end());
	long long maxN = times[times.size() - 1];
	long long left = 1, right = maxN * n; //���� ���� �ɸ��� �ð�, ���� �ɸ��� �ð�
	answer = maxN * n;
	while (left <= right) {
		long long mid = (left + right) / 2;//�߰���
		long long sum = 0;
		for (int i = 0; i<times.size(); i++)
			sum += mid / times[i];//mid���϶� i��° �ɻ��������� ����� �����ų �� �ִ��� 
		if (sum<n) //n���� ���� �����Ű�� 
			left = mid + 1;
		else {//n���� ���ų� ũ�� �����Ű��
			answer = min(answer, mid);
			right = mid - 1;
		}
	}
	return answer;
}