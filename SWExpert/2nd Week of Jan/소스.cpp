#include <string>
#include <vector>
#include <queue>
#include <list>
using namespace std;
int solution(int bridge_length, int weight, vector<int> &truck_weights) {
	list<int> passing;
	queue<int> passed, waiting;
	passing.push_back(truck_weights[0]);
	for (int i = 1; i<truck_weights.size(); i++)
		waiting.push(truck_weights[i]);
	while (!waiting.empty()) {
		if (passing.size()>bridge_length) passing.pop_front();
		int curW = waiting.front(); //���� ���������� Ʈ���� ����
									//���� �ٸ����� Ʈ���� ����
		int totalW = 0;
		for (auto iter : passing) totalW += iter;
		if (totalW + curW <= weight) {
			passing.push_back(curW);
			passed.push(curW);
			waiting.pop();
		}
		else {
			passing.push_back(0);
			passed.push(0);
		}
	}
	return passed.size() + bridge_length;
}
int main() {
	vector<int>v;
	v.push_back(7);
	v.push_back(4);
	v.push_back(6);
	v.push_back(5);
	solution(2, 10, v);
	return 0;
}