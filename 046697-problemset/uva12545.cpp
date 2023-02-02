#include <iostream>
#include <cstdio>
using namespace std;
int T, ans; string strx, stry; int data;
int cnt[10]; // 0: 0->1    1: 1->0    2: ?->0   3: ?->1
// 妈的，这怎么对的啊？
/*
0可变1， 1不可变0
3
??? 0
101 1
01
10
110001
000000

0 1
1 1
*/
/*
0110
1111

00011??0
01111010

*/
signed main() {
	cin >> T;
	while(T--) {
		ans=0; memset(cnt, 0, sizeof(cnt));
		cin >> strx >> stry;
		for(int i=0; i<stry.length(); i++) {

			// 不要这么写！！两个字符串之间没有任何关系，不能建立定死的映射！！给我他妈重写！！！！
			// 可以这么写！！两个字符串怎么他妈没关系了，1不能换为0让你吃了？？给我他妈该回去！！！

			// 晕晕
			if 	   (strx[i]=='0' && stry[i]=='1') cnt[0]++;
			else if(strx[i]=='1' && stry[i]=='0') cnt[1]++;
			else if(strx[i]=='?' && stry[i]=='0') cnt[2]++;
			else if(strx[i]=='?' && stry[i]=='1') cnt[3]++;

			// if 	   (strx[i]=='0' && stry[i]=='1') st++;
			// else if(strx[i]=='1' && stry[i]=='0') sc++;   // 就这么写就这么写 气死你

			// if(strx[i]=='?') cnt[0][2]++;
			// else cnt[0][strx[i]-'0']++;
			// cnt[1][stry[i]-'0']++;
		}
		ans+=min(cnt[0], cnt[1]);     // step1: exchange 0/1
		if(cnt[0]>cnt[1]) {
			cnt[0]-=cnt[1]; cnt[1]=0;
		}else {
			cnt[1]-=cnt[0]; cnt[0]=0;
		}
		// cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << " " << cnt[3] << endl;
			
		// set <?, 0>(cnt[2]) to exchange with <0, 1>(cnt[0]) ans+=2;
		// set <?, 1>(cnt[3]) to exchange with <1, 0>(cnt[1]) ans+=2;
		if(cnt[2]>cnt[0]) {	
			cnt[2]-=cnt[0];  ans+=(2*cnt[0]);  cnt[0]=0;
		}else {
			cnt[0]-=cnt[2];  ans+=(2*cnt[2]);  cnt[2]=0;
		}
		if(cnt[3]>cnt[1]) {
			cnt[3]-=cnt[1];  ans+=(2*cnt[1]);  cnt[1]=0;
		}else {
			cnt[1]-=cnt[3];  ans+=(2*cnt[3]);  cnt[3]=0;
		}
		ans+=(cnt[0]+cnt[2]+cnt[3]);
		if(!cnt[1]) printf("Case %d: %d\n", ++data, ans);
		else printf("Case %d: -1\n", ++data);
		// 全几把给我重写！！！！！！！！！！！！！！！！！！！！！！

		// ？的数量为cnt[0][2], x中0个数为cnt[0][0]、1个数为cnt[0][1]; 
		// y中0个数为cnt[1][0]、1个数为cnt[1][1]

	}
	return 0;
}