#include <string>
#include <vector>
#include <list>
/*
���α׷��ӽ� ���ǰ�� 
���� 1: �迭�� ȸ��
*/
using namespace std;
bool solution(vector<int> arrA, vector<int> arrB) {
	list<int> l;
	int cnt = arrA.size();
	for (int i = 0; i<arrA.size(); i++) l.push_back(arrA[i]);
	while (cnt--) {
		int back = l.back();
		l.pop_back();
		l.push_front(back);
		bool chk = true;
		int i = 0;
		for (auto iter : l) {
			if (iter == arrB[i])i++;
			else {
				chk = false;
				break;
			}
		}
		if (chk) return true;
	}
	return false;
}