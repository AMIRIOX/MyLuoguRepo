#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;
stack<char> s;
int main() {
    char ch;
    bool oks = true;
    while((ch=getchar())!='@'){
	if(ch=='(') s.push('(');
	else if(ch==')') {
	    if(!s.empty() && s.top()=='(') s.pop();
	    else oks=false;
	}
    }
    if(s.empty() && oks) printf("YES");
    else printf("NO");
    return 0;
}
