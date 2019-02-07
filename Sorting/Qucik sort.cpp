#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
[Quick Sort] (�Ҿ��� ����)
	: pivot�� ������ pivot�� �������� ���� �� ����, ū �� ���������� ���ġ �� pivot�� ����� �ű�
	pivot�� ������ �κи���Ʈ�� ���̰� 1 Ȥ�� 0�� ������ �ݺ�

	nlogn �� �ð� ���⵵�� ������ �ٸ� �˰���麸�� ��������� ������ �߰� �޸� �ʿ� X
	(pivot�� ���� ���� �ܰ迡�� ���ܵǹǷ�)

	-> Best: O(nlogn)
	-> Avg: O(nlogn)
	-> Worst: O(n^2)
*/
void swap(int arr[], int low, int high) {
	int tmp = arr[low];
	arr[low] = arr[high];
	arr[high] = tmp;
}
void quickSort(int arr[], int left, int right) {
	if (left >= right) return;

	int mid = (left + right) / 2;
	int pivot = arr[mid];
	swap(arr, left, mid);

	int low = left + 1, high = right;

	while (1) {
		while (arr[low] <= pivot) low++; //pivot���� ��������
		while (arr[high] > pivot) high--;// pivot���� ū����

		if (low > high) break; 
		swap(arr, low, high);
	}
	swap(arr, left, high);

	quickSort(arr, left, high - 1);
	quickSort(arr, high +1, right);

}
int main(){
	int n = 10;
	int arr[10] = { 41,32,6,16,38,28,19,45,43,49 };
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}