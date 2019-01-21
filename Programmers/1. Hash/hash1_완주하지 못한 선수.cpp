#include <string>
#include <vector>
#include<set>
using namespace std;
string solution(vector<string> participant, vector<string> completion) {
	multiset<string> p, c;//key
	for (int i = 0; i<participant.size(); i++)
		p.insert(participant[i]);
	for (int i = 0; i<completion.size(); i++)
		c.insert(completion[i]);
	for (int i = 0; i<participant.size(); i++) {
		int pName = p.count(participant[i]);//������ set�� ���������� �������(1�̸� �������� ����)
		int cName = c.count(participant[i]);//���� ������ �̸��� ������ set�� ��� �ִ��� 
		if (pName != cName) return participant[i];//���� ������ �̸��� ������ �����ڿ� �ִ� �̸��� ������ �ٸ��� 
	}
}
int main() {
	return 0;
}

