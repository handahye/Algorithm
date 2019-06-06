#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool cmp1(pair<int, int> &a, pair<int, int>&b) {
	return a.second > b.second;
}
bool cmp2(pair<int, int>&a, pair<int, int> &b) {
	return a.first < b.first;
}
int main() {
	int grade[4] = { 3,2,1,2 };
	vector<pair<int, int>> v; //��ȣ, ����
	vector<pair<int, int>> ans;//��ȣ, ���
	for (int i = 1; i <= 4; i++) v.push_back({ i,grade[i - 1] });
	sort(v.begin(), v.end(), cmp1);//���� ������ ����

	int num = 1; //���
	ans.push_back({ v[0].first, num });

	for (int i = 1; i<v.size(); i++) {
		if (v[i].second == v[i - 1].second) { //������ �����ϸ�
			ans.push_back({ v[i].first, num });
		}
		else { //������ �ٸ���
			num = ans.size() + 1; //���ݱ��� ans�� ����ִ� �л��� +1 ���� ���� ����� ��
			ans.push_back({ v[i].first, num });
		}
	}
	sort(ans.begin(), ans.end(), cmp2); //��ȣ ������ ����
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i].second);
	return 0;
}