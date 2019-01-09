#include<iostream>
#include <string>
#include <vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
unordered_multimap<string, int> g;//장르 고유번호
unordered_map<int, int> p;//고유번호 재생수
unordered_map<string, int> m; //장르
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
vector<int> solution(vector<string> &genres, vector<int> &plays) {
	vector<int> answer;
	for (int i = 0; i < genres.size(); i++) {
		g.insert({ genres[i], i });
		p.insert({ i, plays[i] });
		m[genres[i]] += plays[i];
	}
	//장르 순위 구하기
	selectGenre();
	//2곡 뽑기
	for (int i = 0; i < rankGenre.size(); i++) {
		for (auto iter : g) {
			if (iter.first == rankGenre[i].first) {
				int n = iter.second;
				int playNum = p[n];
				rankSong.push_back({ playNum, n });
			}
		}
		sort(rankSong.begin(), rankSong.end(), compare1);
		answer.push_back(rankSong[0].second);
		if (rankSong.size() > 1)
			answer.push_back(rankSong[1].second);
		rankSong.clear();
	}
	return answer;
}
int main() {
	vector<string> a;
	vector<int> b;
	a.push_back("classic");
	a.push_back("pop");
	a.push_back("classic");
	a.push_back("classic");
	a.push_back("pop");
	b.push_back(500);
	b.push_back(600);
	b.push_back(150);
	b.push_back(800);
	b.push_back(2500);
	solution(a, b);
	return 0;
}