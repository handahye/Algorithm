#include<iostream>
using namespace std;
/*3131. 100�� ������ ��� �Ҽ�*/
int main()
{
	bool res[1000000] = { 0, }; //�ڷ����� int�� �θ� ��Ÿ�� ������ ���� ��� ��������..
	
	// ����� �Ҽ��� �ƴϴϱ� �̸� ����صּ� �ߺ��ؼ� ����ϴ� �� ������
	for (int i = 2; i < 1000000; i++) {
		if (res[i])continue;
		for (int j = 2; j*i < 1000000; j++) {
			res[j*i] = 1;
		}
	}

	for (int i = 2; i < 1000000; i++)
		if (!res[i]) printf("%d ", i);
	return 0;
}