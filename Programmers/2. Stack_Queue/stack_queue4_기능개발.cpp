#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> que;
	for (int i = 0; i<progresses.size(); i++) {
		int day = floor((100 - progresses[i]) / speeds[i]);//�۾��ϼ�
		que.push(day);
	}
	int first = que.front(), num = 1;
	que.pop();
	while (!que.empty()) {
		int n = que.front();
		que.pop();
		if (n <= first) num++; //�۾��ϼ��� �� ���� ���
		else {//�� ū���
			answer.push_back(num);
			first = n;//�۾��� �� �ٲ���
			num = 1;
		}
	}
	answer.push_back(num);
	return answer;
}
int main() {
	return 0;
}