#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<list>
using namespace std;
/*
#2161_ī��2
1. 1�� ī�尡 ���� ��, N�� ī�尡 ���� ���� ����
2. ���� ���� �ִ� ī�带 �ٴڿ� ����. �׸��� ���� ���� ī�带 ���� �Ʒ���
3. ���� ������ ī�尡 ���� ���������� �ݺ�
4. ������ ���� ī�� ���
*/
int main() {
	int res = 0;
	int n;
	cin >> n;
	list<int> card;
	for (int i = 1; i <= n; i++) card.push_back(i);
	while(card.size() > 1) {
		int f = card.front();
		card.pop_front();
		int f2 = card.front();
		card.pop_front();
		card.push_back(f2);
	}
	cout << card.back();
	return 0;
}