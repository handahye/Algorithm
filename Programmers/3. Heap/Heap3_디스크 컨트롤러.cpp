#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const vector<int> &a, const vector<int> &b){
	return a[0] < b[0];
}
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int curTime = 0;
	int Jobsize = jobs.size();
	sort(jobs.begin(), jobs.end(), cmp);
	while (!jobs.empty()){
		int curIdx = 0;
		int minN = 987654321;
		for (int i = 0; i < jobs.size(); i++){
			if (curTime >= jobs[i][0]) { //���� �ð����� ������ �� �ִ� �۾���
				if (minN >= curTime + jobs[i][1]){//�� �� ���� ���� ������ �۾� ã��
					minN = curTime + jobs[i][1];
					curIdx = i;
				}
			}
		}
		if (jobs.empty()) break;
		if (minN == 987654321) {//���� �ð����� ������ �� ���� �۾��� ������ �ð� ����
			curTime++;
		}
		else {
			int startTime = jobs[curIdx][0];
			curTime = minN;
			answer += (curTime - startTime);//�� �ҿ�ð�
			jobs.erase(jobs.begin() + curIdx);//vector���� ��������
		}
	}
	return answer / Jobsize;
}