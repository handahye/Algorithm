#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*����Ʈ �ð��ʰ�*/
int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	while (!people.empty()) {
		bool flag = false;
		for (int i = people.size() - 1; i>0; i--) {
			if (people[i] + people[0] <= limit) {
				people.erase(people.begin() + i);
				people.erase(people.begin());
				answer++;
				flag = true;
				break;
			}
		}
		if (!flag) {
			people.erase(people.begin());
			answer++;
		}
	}
	return answer;
}
/*
���� ȿ�������� �¿� �� �ִ� ���: ���� ������ ��� + ���� ���ſ� ���
*/
int solution(vector<int> people, int limit) {
	int answer = people.size();
	sort(people.begin(), people.end());
	int i = 0, j = people.size() - 1;
	while (i < j) {
		if (people[i] + people[j] <= limit)//���� ���ſ� ����� ���� ������ ����� ���� Ż �� �ִ���
			i++, j--; //�Ѵ� �¿�
		else if (people[i] + people[j] > limit) 
			j--;//���� ��Ÿ�� ���ſ� ����� �¿�
	}
	return answer-i;
}