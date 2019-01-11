#include <string>
#include <vector>
#include <queue>
#include <list>
using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 1;
	list<int> passing;
	queue<int> waiting;
	passing.push_back(truck_weights[0]);
	for (int i = 1; i<truck_weights.size(); i++) waiting.push(truck_weights[i]);
	while (!waiting.empty()) {
		int curW = waiting.front(); //���� ���������� Ʈ���� ����
		int totalW = 0;
		if (passing.size() == bridge_length) passing.pop_front();//�ϳ��� Ʈ���� �ٸ��� �� �ǳʸ�
		for (auto iter : passing) totalW += iter; //���� �ٸ����� Ʈ���� ����

		if (totalW + curW <= weight) { //���� Ʈ���� �ٸ����� ������ �� ������
			passing.push_back(curW);//passing list�� ����
			waiting.pop();//waiting queue���� ����
		}
		else
			passing.push_back(0);//����������
		time++;//�ð� ����
	}
	return time + bridge_length;//��⿡�� ���������� ���� Ʈ���� �ٸ����̸�ŭ �� ���ߵǴϱ�
}
int main() {
	return 0;
}