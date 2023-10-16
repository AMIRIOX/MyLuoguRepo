#include <iostream>
#include <cstdio>
using namespace std;
int ans, c;
signed int main() {
	while((c=getchar())!='\n') if(c!=' ' && c!='\n') ans++;
	cout << ans << endl;
	return 0;
}