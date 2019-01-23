#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
1. ���� ������ ���������� �ǵ��� ����
2. ���� ���� ���� ������ ī�޶� ��ġ��
3. ���������� Ž���ϸ鼭 ���Ե��� ������ �� ������ ī�޶� �ٽ� ��ġ
4. �� �ݺ�..
*/
bool cmp(vector<int>&a, vector<int>&b) {
	return a[1]<b[1];
}
int solution(vector<vector<int>> routes) {
	int answer = 0;
	int camera = 0, cur = 0, carNum = 0;
	sort(routes.begin(), routes.end(), cmp);//����
	while (1) {
		if (carNum == routes.size()) return answer; //��� ���� �� üũ���� �� ���� ����
		camera = routes[cur][1]; //ī�޶� ��ġ ����
		answer++;
		carNum++;
		for (int i = cur + 1; i < routes.size(); i++) { //���� ������ Ž���ϸ鼭 ���Ե��� �ʴ� ���� ã��
			if (routes[i][0] > routes[cur][1]) {
				cur = i;//�� �������� �ٽ� ī�޶� ��ġ 
				break;
			}
			carNum++;//������ ����
		}
	}
}
