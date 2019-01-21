#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
	stack<char> s;
	int answer = 0;
	bool chk = false;
	for (int i = 0; i<arrangement.size(); i++) {
		if (arrangement[i] == '(') {
			s.push(arrangement[i]);
			chk = true;
		}
		else {
			s.pop();
			if (chk) answer += s.size(); //���� ���� ��ȣ -> ������
			else answer += 1; //���� �ݴ� ��ȣ -> �������� ��   
			chk = false;
		}
	}
	return answer;
}
int main() {
	
	return 0;
}