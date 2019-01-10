#include <string>
#include <vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
unordered_multimap<string, int> g;//�帣 ������ȣ
unordered_map<int, int> p;//������ȣ �����
unordered_map<string, int> m; //�帣
vector<pair<int, int>> rankSong;
vector<pair<string, int>> rankGenre;
bool compare1(pair<int, int>&a, pair<int, int>&b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}
bool compare2(pair<string, int>&a, pair<string, int>&b) {
	return a.second > b.second;
}
void selectGenre() {
	for (auto iter : m)
		rankGenre.push_back({ iter.first, iter.second });
	sort(rankGenre.begin(), rankGenre.end(), compare2);
}
void selectSong(string genre) {
	for (auto iter : g) {
		if (iter.first == genre) {
			int n = iter.second;
			int playNum = p[n];
			rankSong.push_back({ playNum, n });
		}
	}
}
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	for (int i = 0; i < genres.size(); i++) {
		g.insert({ genres[i], i });//{�帣, ������ȣ}->multimap key �ߺ� ����
		p.insert({ i, plays[i] });//{������ȣ, ���Ƚ��}
		m[genres[i]] += plays[i];//{�帣, �帣�� �� ���Ƚ��} -> map key �ߺ� �ȵ�
	}
	//�帣 ���� ���ϱ�
	selectGenre();
	//2�� �̱�
	for (int i = 0; i < rankGenre.size(); i++) {
		selectSong(rankGenre[i].first);
		sort(rankSong.begin(), rankSong.end(), compare1);
		answer.push_back(rankSong[0].second);
		if (rankSong.size() > 1)
			answer.push_back(rankSong[1].second);
		rankSong.clear();
	}
	return answer;
}
int main() {
	
	return 0;
}