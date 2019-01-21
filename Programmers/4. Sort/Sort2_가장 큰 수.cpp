#include <string>
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
**ó�� ������ ���**
1. vector<string>�� numbers�� ���ڸ� ���� ��, ������������ ����
  <3, 30, 34, 5, 9 ---> 9, 5, 34, 30, 3>

2. ���ڸ� �� �̻��� ���, �� ���� ���ڸ� ��������
	1) �� ���� ���ں��� �� ���� ���ڰ� ũ�� �տ� ��
	2) �� ���� ���ں��� �� ���� ���ڰ� ������ �ڿ� �� (ù idx�� �����ص�)

3. ���ڸ� �� �� ���,
	���� 2-2)���� ���ڰ� ������ ������ idx�� ���ڸ� ����
	�ȵ�� ������ �׳� ���� ����
ex) [6, 671, 619] -> 671 6 619

==> ������ �̷��� Ǯ�� [12, 121] �� ��� 12 121�� ����������, 
�� Ǯ�̴� 121 12�� ������ �ȴ�.
*/
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> s;
	for (int i = 0; i < numbers.size(); i++) s.push_back(to_string(numbers[i]));
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());

	int chk[10] = { 0, };
	int idx = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i].size() > 1 && s[i].at(1) >= s[i].at(0)) answer += s[i];
		else if (s[i].size() > 1 && s[i].at(1) < s[i].at(0)) {
			if (!chk[s[i].at(0) - '0']) idx = answer.size(); //�ε��� ����
			answer += s[i];
			chk[s[i].at(0) - '0'] = true;
		}
		else if (s[i].size() == 1) {
			if (chk[s[i].at(0) - '0']) {
				answer.insert(idx, s[i]);
			}
			else answer += s[i].at(0);
		}
	}
	if (answer.at(0) == '0') return "0";
	else return answer;
}

/*
**�ٸ� ��� �ڵ� ����**
string�� ���� ��ų�� �� �� �μ��� �ٲ� ���ؼ� 
���� �� ū�� ���ϸ鼭 ���Ľ�Ŵ,,

[121, 12]
num1: 121+12 = 12112
num2: 12+121 = 12121 

12121>12112 

+) answer�� ù��° idx�� 0�� ���� ������ 0 
answer�� [0, 0, 0, 0] �̷������� 0�� �ߺ��Ǿ� �� ��찡 �־ 
*/
bool compare(const string &a, const string &b) {
	string num1 = a + b;
	string num2 = b + a;
	if (num1 > num2) return true;
	else return false;
}
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> s;
	for (int i = 0; i <numbers.size(); i++) s.push_back(to_string(numbers[i]));//string���� �ٲ���
	sort(s.begin(), s.end(), compare);//����
	for (int i = 0; i<s.size(); i++) answer += s[i];
	if (answer.at(0) == '0') return "0";
	else return answer;
}