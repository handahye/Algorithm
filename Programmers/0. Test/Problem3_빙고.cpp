#include <vector>
#include <string.h>
using namespace std;
bool visit[501 * 501];
int solution(vector<vector<int>> board, vector<int> nums) { //������, ������� �������
	int answer = 0;
	memset(visit, false, sizeof(visit));
	for (int i = 0; i<nums.size(); i++) visit[nums[i]] = true;
	//������
	for (int i = 0; i<board.size(); i++) {
		bool chk = true;
		for (int j = 0; j<board.size(); j++) {
			if (!visit[board[i][j]]) {
				chk = false;
				break;
			}
		}
		if (chk) answer++;
		chk = true;
		for (int j = 0; j<board.size(); j++) {
			if (!visit[board[j][i]]) {
				chk = false;
				break;
			}
		}
		if (chk) answer++;
	}

	//������ �Ʒ� �밢��
	bool chk = true;
	for (int i = 0; i<board.size(); i++) {
		if (!visit[board[i][i]]) {
			chk = false;
			break;
		}
	}
	if (chk) answer++;
	//���� �Ʒ� �밢��
	chk = true;
	for (int i = 0; i<board.size(); i++) {
		if (!visit[board[board.size() - i - 1][i]]) {
			chk = false;
			break;
		}
	}
	if (chk) answer++;
	return answer;
}