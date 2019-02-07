#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
[Selection Sort: �Ҿ��� ����] 
	: n��° �ڸ��� � ���Ҹ� ������ ������ ��ü�ϴ� �˰���
	�־��� �迭 �� �ּڰ��� ã�� n��°�� ��ġ�� ���� ��ü 
	==> �� ������ �ϳ��� ���Ұ� ���� �� ���� �ݺ�

	-> Best: O(n^2)
	-> Avg: O(n^2)
	-> Worst: O(n^2)
*/
int main(){
	int n = 10;
	int arr[10] = { 41,32,6,16,38,28,19,45,43,49 };
	int index = 0;
	for (int i = 0; i < n; i++) {
		index = i; //index�� ���� ���� ���� ã�Ƽ� ���� 
		for (int j = i+1; j < n; j++) {
			if (arr[j] < arr[index]) {
				index = j;
			}
		}
		int tmp = arr[index];
		arr[index] = arr[i];
		arr[i] = tmp;
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}