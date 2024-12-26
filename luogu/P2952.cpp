#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
int S, count, arg;
deque<int> q;
char c1,c2;
signed main() {
	scanf("%d", &S);
	for(int i=1; i<=S; i++) {
		cin >> c1 >> c2;
		if(c1=='A') {
			if(c2=='L') q.push_front(++count);
			else q.push_back(++count);
		}else if(c1=='D') { 
			cin >> arg;
			if(c2=='L') while(arg-- && !q.empty()) q.pop_front();
			else while(arg-- && !q.empty()) q.pop_back();
		}
	}
	while(!q.empty()) {
		cout << q.front() << endl;
		q.pop_front();
	}
	return 0;
}