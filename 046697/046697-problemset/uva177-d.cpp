#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
/*
|_
 _|
^
   _   _
  |_|_| |_
   _|    _|
|_|
^
_| // 这个玩意每次顺时针旋转90°
^
   _
|_| |_
     _|
^
*/
const int maxn=1020;
char arr[maxn][maxn];
int n;
void rotate(int ht, int wt, int& orght, int& orgwt) {
	orght+=wt; orgwt+=ht;
}
signed main() {
	while(cin >> n) {
		int hx=1, wx=2;
		arr[1][1]='_'; arr[1][2]='|';
		for(int i=1; i<n; i++) rotate(hx, wx, hx, wx);

	}
	return 0;
}