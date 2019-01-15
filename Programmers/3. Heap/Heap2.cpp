#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	//1. �켱���� ť ��� -> ���޷��� ū ������ ������ ���ؼ�
	priority_queue<int> que; 
	int idx = 0;
	while (1) {
		//2. ���� ������ stock���� k�ϱ��� ��ƿ �� ������ return
		if (stock >= k) return answer; 
		//3. ���� ������ �ִ� �а��� ������ ��ƿ �� �ִ� ������ ���� �� �ִ� ������ �켱���� ť�� ����
		for (int i = idx; i<dates.size(); i++) {
			if (dates[i] <= stock) que.push(supplies[i]);
			else {//��ƿ �� ���� ��¥ idx ����
				idx = i;
				break;
			}
		}
		//4. �켱���� ť���� ���� ū ���޷��� ������ 
		answer++;
		stock += que.top();//stock�� �� �����ؼ� ����
		que.pop();
	}
	return answer;
}