#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool solution(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end());//sort��
	for (int i = 0; i < phone_book.size() - 1; i++) {
		string s1 = phone_book[i], s2 = phone_book[i + 1];
		int len = 0;
		for (int idx = 0; idx < s1.size(); idx++) {
			if (s1[idx] != s2[idx]) break;//���ξ �ٸ��� ����
			len++;//���ξ��� ���̸� ��
		}
		if (len == s1.size()) return false; //�� ���̿� ���ξ��� ���̰� �Ȱ����� return 
	}
	return true;//���ξ �ٸ� ���
}
int main() {
	return 0;
}