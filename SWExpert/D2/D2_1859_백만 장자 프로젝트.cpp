#include <iostream>
using namespace std;
int T, N;
int arr[1000001];
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		long long totalSum = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		int max = arr[N - 1]; //���� ������ ���� max�� ����
		for (int i = N - 1; i >= 0; i--) {//n-1���� for�� ���Ƽ� 
			if (max >= arr[i]) totalSum += max - arr[i]; //���� max������ ���� ��� ���� ��(totalSum�� �� ������)
			else max = arr[i];//���� max������ ū ���, ���� index�� ������ max�� ��������
		}
		printf("#%d %lld\n", t, totalSum);
	}
	return 0;
}