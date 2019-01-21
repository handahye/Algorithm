#include <string>
#include <vector>
#include <queue>
#include <list>
using namespace std;
/*
- list(passing):
1) ���� �ٸ��� ������ �ִ� Ʈ������ ���Ը� ����ϴϱ� iterator�� ����ϱ� ����
2) push�Ҷ� ���� �ٸ����� ������ �ִ� Ʈ������ �� �ڿ� push�ϰ�
�ٸ��� �� ������ ��� �� ���� Ʈ���� pop�ϱ� ���ؼ�

- queue(waiting): �ٸ��� �������� ���� ��ٸ��� Ʈ���� queue�� ����
*/
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	/*
	<1��>
	passing: | 7 |  
	waiting: | 4 | 5 | 6 |

	<2��> 
	passing: | 7 | -> | 7 | 0 | [���� 4�� Ʈ���� �� �������ϱ� 0 push]
	waiting: | 4 | 5 | 6 |

	<3��> 
	[pssing size = 2, ���� 7�� Ʈ���� �ٸ� �� �ǳͰŴϱ� pop]
	passing: | 7 | 0 | -> | 0 | -> | 0 | 4 |
	waiting: | 5 | 6 |

	<4��> 
	passing: | 0 | 4 | -> | 4 | -> | 4 | 5 |
	waiting: | 6 |

	<5��> 
	passing: | 4 | 5 | -> | 5 | -> | 5 | 0 |
	waiting: | 6 |

	<6��> 
	passing: | 5 | 0 | -> | 0 | -> | 0 | 6 |
	waiting: empty

	����: 6�� + �ٸ�����(2) = 8��
	*/
	int time = 1;
	list<int> passing;
	queue<int> waiting;
	//1. ù��°�� �������� �ϴ� Ʈ�� passing list�� ����
	passing.push_back(truck_weights[0]);
	//2. ������� Ʈ���� queue�� ����
	for (int i = 1; i<truck_weights.size(); i++) waiting.push(truck_weights[i]);

	//3. ������� Ʈ������ ���������� while�� ����
	while (!waiting.empty()) {
		//4. passing list�� ũ�Ⱑ �ٸ� ���̿� �������� �� ���� Ʈ���� �ٸ��� �� �ǳͰŴϱ� pop����
		if (passing.size() == bridge_length) passing.pop_front();

		//5. ���� �ٸ����� Ʈ���� ���� ���
		for (auto iter : passing) totalW += iter;

		int curW = waiting.front(); 
		int totalW = 0;
		//6-1) ������� Ʈ���� ������ �� �ִ� ��� (����ϴ� Ʈ���� ����+�ٸ��� Ʈ������<=�ٸ��� �ߴ볾 �� �ִ� ����)
		if (totalW + curW <= weight) {
			passing.push_back(curW);//passing list�� ����
			waiting.pop();//waiting queue���� ����
		}
		//6-2) ������ �� ���� ���
		else
			passing.push_back(0);//�� ���� Ʈ���� �ٸ� �� �ǳԴ��� üũ�Ϸ���

		//7. �ð� ����
		time++;
	}
	return time + bridge_length;//waiting queue���� ���������� ���� Ʈ���� �ٸ������� �������� �����Ŵϱ� �ٸ����̸�ŭ �� ������! 
}
int main() {
	return 0;
}