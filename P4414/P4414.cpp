#include <stdc++.h>
using namespace std;
struct alluni {
	int u[4];
	int operator[](char a) {
		int index=0;
		switch (a) {
		case 'A': {
			index = 0;
			break;
		}
		case 'B': {
			index = 1;
			break;
		}
		case 'C': {
			index = 2;
			break;
		}
		}
		return u[index];
	}
};
int main() {
	alluni an;
	for (int i = 0; i < 3; i++) {
		cin >> an.u[i];
	}
	sort(an.u, (an.u)+3);
	char ch;
	for (int i = 0; i < 3; i++) {
		cin >> ch;
		cout << an[ch] <<" ";
	}
	return 0;
}