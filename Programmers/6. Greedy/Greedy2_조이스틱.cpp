#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
int solution(string name) {
	int answer = 0;
	int upDown[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };
	for (int i = 0; i < name.size(); i++) {
		answer += upDown[name.at(i) - 'A'];
	} //�� �Ʒ��� �������� �� �ּ� ������ 
	int leftRight = name.size() - 1;
	int len = name.size();
	for (int i = 0; i < name.size(); i++) {
		int next = i + 1;
		while (1) {//���� ��ġ���� A�� ������ �������� ���� ����
			if (next == name.size() || name.at(next) != 'A') break;
			next++;
		}
		int tmp = min(i, len - next); //�������� ������ �� ���°Ͱ� �ڷ� �Ѿ� ���� �� �� ª�� �� 
		leftRight = min(leftRight, i + (len - next) + tmp);
	}
	answer += leftRight;
	return answer;
}