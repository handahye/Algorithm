
/*Programmers_Greedy3_ū �� �����*/

#include <string>
#include <vector>
using namespace std;
string solution(string number, int k) {
	string answer = "";
	vector<int> v;
	for (int i = 0; i<number.size(); i++) { //int�� �ٲ㼭 vector ����
		int val = number.at(i) - '0';
		v.push_back(val);
	}
	int cur = number.length() - k; //�����ؾ� �ϴ� ���� ����
	int selectIdx = -1;//���õ� �ε���
	while (1) {
		int max = -1, maxIdx = -1;
		if (answer.length() == number.length() - k) return answer;//��� �� ���õ� ��� ����
		for (int i = selectIdx + 1; i <= number.length() - cur; i++) {//���õ� ���� �ε������� ���� ������ �������� for�� ���鼭 ���� ū �� ã��
			if (v[i]>max) {
				max = v[i];
				maxIdx = i;
			}
		}
		selectIdx = maxIdx;
		answer += (to_string(v[selectIdx]));
		cur--;
	}

	return answer;
}