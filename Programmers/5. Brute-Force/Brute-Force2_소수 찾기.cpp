#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
bool prime[9999999];
bool chk[9999999];
bool Idxvisit[10];
vector<char> v;
int answer = 0;
void dfs(int val) {
	if (prime[val] == false && !chk[val]) { //�Ҽ��̰� üũ���� ���� �Ҽ���
		answer++;
		chk[val] = true;
	}
	for (int i = 0; i < v.size(); i++) {
		if (!Idxvisit[i]) {
			Idxvisit[i] = true;
			string tmp = to_string(val) + v[i];
			int num = atoi(tmp.c_str());
			dfs(num);
			Idxvisit[i] = false;
		}
	}
}
//�����佺�׳׽��� ü �����
void calPrime() {
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i <= sqrt(9999999); i++) {
		if (prime[i]) continue;
		for (int j = i + i; j <= 9999999; j += i) {
			prime[j] = true;//����� �Ǵ� �͵��� ��� üũ
		}
	}
}
void init() {
	answer = 0;
	memset(Idxvisit, 0, sizeof(Idxvisit));
	memset(chk, 0, sizeof(chk));
	v.clear();
}
int solution(string numbers) {
	init();
	for (int i = 0; i<numbers.length(); i++)
		v.push_back(numbers.at(i));
	sort(v.begin(), v.end());
	calPrime();
	for (int i = 0; i<v.size(); i++) {
		int val = v[i] - '0';
		if (val == 0) continue;
		Idxvisit[i] = true;
		dfs(val);
		Idxvisit[i] = false;
	}

	return answer;
}