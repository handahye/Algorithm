#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
[Insertion Sort]
	: "�� ��°" ���Һ��� ������ ������ �ڷ��� ���� ���Ե� ��ġ�� ã��, ������ �ڷ���� �ڷ� �̵�
	�ڷᰡ ���� ��κ��� ���ĵǾ� ���� ��쿡 ȿ������ �� ���� 
	-> Best: O(n)
	-> Avg: O(n^2)
	-> Worst: O(n^2)
*/
int main(){
	int n = 10;
	int arr[10] = { 41,32,6,16,38,28,19,45,43,49 };
	int i, j;
	for (i = 1; i < n; i++) { //�ι�° ���Һ��� ����! 
		int key = arr[i];
		for (j = i-1; j>=0; j--) {
			if (arr[j] > key) {
				arr[j + 1] = arr[j]; //��ĭ�� �о�� ��
			}
			else break; //������ �̹� ���ĵǾ� �����Ƿ� �� ���� ���� ����
		}
		arr[j + 1] = key;
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}