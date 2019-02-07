#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
[Merge Sort]
	: ���� ���� �˰����� �ϳ�
	���ڵ� �迭�� ���̰� 1�� �� ������ �ɰ� �� �պ��ϴ� �������� ���� ����
	i) 2���� ����Ʈ�� ������ ó������ �ϳ��� ���Ͽ� ���� ���� ���ο� ����Ʈ(Sorted)�� �ű�
	ii) �� ����Ʈ �� �ϳ��� ���� �� ���� �ݺ�
	iii) ���� ����Ʈ�� ������ ���ο� ����Ʈ(Sorted)�� �ڷ� ����

	�߰����� ������ �ҿ�� �� ����
	==> ���ڵ尡 ���� ��� ���Ḯ��Ʈ�� ����ϸ� �ε����� �����ϸ� �Ǳ� ������ ���� ȿ������ ���� ���

	-> Best: O(nlogn)
	-> Avg: O(nlogn)
	-> Worst: O(nlogn)
*/
int sorted[10]; //�߰����� ����
void merge(int arr[], int left, int mid, int right) {
	int i, j, k;
	i = left, j = mid + 1, k = left;

	//���� ���ĵ� list�� �պ�
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) sorted[k++] = arr[i++];
		else sorted[k++] = arr[j++];
	}
	//���� �ִ� ���� ����
	if (i > mid) {
		for (int l = j; l <= right; l++)
			sorted[k++] = arr[l];
	}
	else {
		for (int l = i; l <= mid; l++)
			sorted[k++] = arr[l];
	}

	//�ӽ� �迭�� arr�� �ٽ� �纹����
	for (int l = left; l <= right; l++)
		arr[l] = sorted[l];
}
void divide(int arr[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		divide(arr, left, mid);
		divide(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
int main(){
	int n = 10;
	int arr[10] = { 41,32,6,16,38,28,19,45,43,49 };
	divide(arr, 0, n - 1);
	return 0;
}