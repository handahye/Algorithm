#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int solution(string name) {
	int answer = 0;
	int left = 0, right = 0;
	answer = min(name[0] - 'A', 'Z' - name[0] + 1);
	//1. ������ A ���� ����
	for (int i = 1;i<name.size();i++) {
		if (name[i] == 'A')right++;
		else break;
	}
	//2. ���� A ���� ����
	for (int i = name.size() - 1;i>0;i--) {
		if (name[i] == 'A') left++;
		else break;
	}

	if (right <= left) {	//3-1) ���������� �̵��ϴ� ���
		for (int i = 1;i<name.size() - left;i++) {
			answer++;
			answer += min(name[i] - 'A', 'Z' - name[i] + 1);
		}
	}
	else {	//3-2) �������� �̵��ϴ� ���
		for (int i = name.size() - 1;i>right;i--) {
			answer++;
			answer += min(name[i] - 'A', 'Z' - name[i] + 1);
		}
	}

	return answer;
}
