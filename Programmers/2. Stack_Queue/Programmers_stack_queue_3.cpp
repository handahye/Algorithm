#include <string>
#include <vector>
#include <queue>
#include <list>
using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 1;
	/*
	- list: 
		1) ���� �ٸ��� ������ �ִ� Ʈ������ ���Ը� ����ϴϱ� iterator�� ����ϱ� ����
		2) push�Ҷ� ���� �ٸ����� ������ �ִ� Ʈ������ �� �ڿ� push�ϰ�
		�ٸ��� �� ������ ��� �� ���� Ʈ���� pop�ϱ� ���ؼ� 

	- queue: �ٸ��� �������� ���� ��ٸ��� Ʈ���� queue�� ����(waiting)
	*/
	list<int> passing;
	queue<int> waiting;

	//1. ù��°�� �������� �ϴ� Ʈ�� passing list�� ����
	passing.push_back(truck_weights[0]);
	//2. ������� Ʈ���� queue�� ����
	for (int i = 1; i<truck_weights.size(); i++) waiting.push(truck_weights[i]);

	//3. ������� Ʈ������ ���������� while�� ����
	while (!waiting.empty()) {
		//4. passing list�� ũ�Ⱑ �ٸ� ���̿� �������� �� ���� Ʈ���� �ٸ��� �� �ǳͰŴϱ� pop����
		if (passing.size() == bridge_length) passing.pop_front();

		//5. ���� �ٸ����� Ʈ���� ���� ���
		for (auto iter : passing) totalW += iter;

		int curW = waiting.front(); 
		int totalW = 0;
		//6-1) ������� Ʈ���� ������ �� �ִ� ��� (����ϴ� Ʈ���� ����+�ٸ��� Ʈ������<=�ٸ��� �ߴ볾 �� �ִ� ����)
		if (totalW + curW <= weight) {
			passing.push_back(curW);//passing list�� ����
			waiting.pop();//waiting queue���� ����
		}
		//6-2) ������ �� ���� ���
		else
			passing.push_back(0);//�� ���� Ʈ���� �ٸ� �� �ǳԴ��� üũ�Ϸ���
		/*
		<1��> | 7 |
		<2��> | 7 | -> | 7 | 0 | [���� 4�� Ʈ���� �� �������ϱ� 0 push]
		<3��> [pssing size = 2, ���� 7�� Ʈ���� �ٸ� �� �ǳͰŴϱ� pop] | 7 | 0 | -> | 0 | -> | 0 | 4 | 
		<4��> | 0 | 4 | -> | 4 | -> | 4 | 5 | 
		<5��> | 4 | 5 | -> | 5 | -> | 5 | 0 |
		<6��> | 5 | 0 | -> | 0 | -> | 0 | 6 | 
		
		����: 6�� + �ٸ�����(2) = 8��
		*/

		//7. �ð� ����
		time++;
	}
	return time + bridge_length;//waiting queue���� ���������� ���� Ʈ���� �ٸ������� �������� �����Ŵϱ� �ٸ����̸�ŭ �� ������! 
}
int main() {
	return 0;
}