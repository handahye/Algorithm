#include <iostream>
#include<string.h>
#include<string>
using namespace std;
int T;
string str;
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> str;
		int len = str.size();
		//1�� ���
		for (int i = 0; i < len; i++) {
			if (i == 0) printf("..#..");
			else printf(".#..");
		}
		printf("\n");
		//2�� ���
		for (int i = 0; i < len; i++) {
			if (i == 0) printf(".#.#.");
			else printf("#.#.");
		}
		printf("\n");
		//3�� ���
		for (int i = 0; i < len; i++) {
			if (i == 0) printf("#.%c.#",str.at(i));
			else printf(".%c.#", str.at(i));
		}
		printf("\n");
		//4�� ���
		for (int i = 0; i < len; i++) {
			if (i == 0) printf(".#.#.");
			else printf("#.#.");
		}
		printf("\n");
		//5�� ���
		for (int i = 0; i < len; i++) {
			if (i == 0) printf("..#..");
			else printf(".#..");
		}
		printf("\n");
	}
	return 0;
}