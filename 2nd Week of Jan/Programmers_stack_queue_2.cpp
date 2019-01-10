#include <string>
#include <vector>
#include <list>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 1;
	list<pair<int, int>> doc;//�߿䵵 ��ġ
	for (int i = 0; i < priorities.size(); i++) 
		doc.push_back({ priorities[i],i });
	while (1) {
		bool chk = true;
		int curPriority = doc.front().first;
		int curLocation = doc.front().second;
		doc.pop_front();
		for (auto iter : doc) {
			int nextPriority = iter.first;
			if (nextPriority > curPriority) { //�� ū �߿䵵�� ������
				doc.push_back({ curPriority ,curLocation });
				chk = false;
				break;
			}
		}
		if (chk) {//�� ū �߿䵵�� ������
			if (curLocation == location) return answer;
			answer++;
		}
	}
}
int main() {
	return 0;
}