#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
[Bubble Sort]
	: ���� ������ �� ���Ҹ� �˻��Ͽ� ���������ν� �����ϴ� �˰���
	���� ū ���ڰ� �� �ڷ� ��. �� �ڴ� ���� ���ص� ��
	-> Best: O(n^2)
	-> Avg: O(n^2)
	-> Worst: O(n^2)
*/
int main(){
	int n = 10;
	int arr[10] = { 41,32,6,16,38,28,19,45,43,49 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	return 0;
}