
int main() {
	cout << " ��";
	int T;
	cin >> T;


	for (int k = 1; k <= T; k++) {
		int N, Q;
		cin >> N >> Q;

		int cow[100001];
		int L[100001], R[100001];
		int one[100001], two[100001], thr[100001];

		for (int i = 1; i <= N; i++) { //N�� �� ǰ�� �Է¹�
			cin >> cow[i];
		}

		for (int j = 0; j < Q; j++) { //���� �Է¹�
			cin >> L[j] >> R[j];

			one[j] = 0;
			two[j] = 0;
			thr[j] = 0;

			for (int i = L[j]; i <= R[j]; i++) { //ǰ�� �� ���ϱ�
				if (cow[i] == 1) {
					one[j]++;
				}
				else if (cow[i] == 2) {
					two[j]++;
				}
				else {
					thr[j]++;
				}
			}

		}
		//�� ���
		cout << "#" << k << endl;
		for (int j = 0; j < Q; j++) {
			cout << one[j] << " " << two[j] << " " << thr[j] << endl;
		}

	}

	return 0;
}