#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<stack>
#include<math.h>
using namespace std;
/*
D4_��ȣ ¦����
*/
bool chkBar(char a, char b) {
	if (a == '('&&b == ')') return true;
	else if (a == '{'&&b == '}') return true;
	else if (a == '['&&b == ']') return true;
	else if (a == '<'&&b == '>') return true;
	else return false;
}
int main() {
	//int T;
	//cin >> T;
	for (int t = 1; t <= 10; t++) {
		bool chk = true;
		int N;
		cin >> N;
		vector<char> v;
		for (int i = 0; i < N; i++) {
			char c;
			cin >> c;
			v.push_back(c);
		}
		stack<char> s;
		if (v[0] == '(' || v[0] == '{' || v[0] == '[' || v[0] == '<') s.push(v[0]); //ó���� ���� ��ȣ�� stack�� �ֱ�
		else chk = false; //ó���� �ݴ� ��ȣ�� �ȵǴ� ���
		int idx = 0;
		while (!s.empty()) {
			idx++;
			if (v[idx] == '(' || v[idx] == '{' || v[idx] == '[' || v[idx] == '<') {
				s.push(v[idx]);
				continue; //���� ��ȣ�� ������ ��� stack�� ����
			}
			else {
				char t = s.top(); //�ݴ� ��ȣ�� ������ �ٷ� ���� ���� ��ȣ�� ������ Ȯ��
				if (chkBar(t, v[idx])) {
					s.pop();
					continue;
				}
				else { //���� �ƴϸ� �ȵǴ� ���
					chk = false;
					break;
				}
			}
		}
		if(!chk)
			cout << "#" << t << " " <<"0"<< endl;
		else
			cout << "#" << t << " " << "1" << endl;
	}
	return 0;
}