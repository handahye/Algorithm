#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int histo[4] = { 2,2,2,3 };
	int size = 4;
	int maxN = 0;
	for (int i = 0; i < size - 2; i++) { //(������׷��� ũ�� -2 )�� �ε��� �϶��� ���� ���� �� �����ϱ�
		for (int j = i + 2; j < size; j++) { // i+2���� ���� ���� �� ���� 
			int width = j - i - 1; //���γ���
			int hight = min(histo[i], histo[j]); //���α��̰� �� ª���� ���̰� ��
			maxN = max(maxN, width*hight); //������� �� ���� ���̰� ������ maxN���� ����
		}
	}
	printf("%d", maxN);
	return 0;
}