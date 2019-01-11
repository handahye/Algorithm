#include<iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;
/*
ó��: dfs�� ���� 
���� ���: (type1�ǰ���+1)*(type2�ǰ���+1)*... -1
+1�� �� �Դ� ��츦 ���, �������� -1�� ��� ���� ���� �ʴ� ������
�ñ� ������ ����
*/
int solution(vector<vector<string>> clothes) {
	int res = 1;
	map<string, vector<string>> m;
	for (int i = 0; i < clothes.size(); i++)
		m[clothes[i][1]].push_back(clothes[i][0]);
	for (auto iter : m)
		res *= iter.second.size() + 1;
	return res - 1;
}
int main() {
	return 0;
}