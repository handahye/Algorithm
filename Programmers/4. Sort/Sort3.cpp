#i#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
1. ���� �������� ����
2. h-index�� �ϳ��� ������Ű�ٰ� 
���� h-index�� citations���� Ŀ���� ���� ����
citations�� ����ִ� ���� �̻� �ο�ȰŴϱ�
*/
bool compare(int &a, int &b) {
	return a > b;
}
int solution(vector<int> citations) {
	sort(citations.begin(), citations.end(), compare);
	int h_idx = 0;
	while (1) {
		if (citations[h_idx] < h_idx+1) break;
		if (h_idx == citations.size()) break;
		h_idx++;
	}
	return h_idx;
}
int main() {
	
	return 0;
}