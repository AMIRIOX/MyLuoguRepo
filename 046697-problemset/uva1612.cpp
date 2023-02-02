#include <iostream>
#include <cstdio>
#define DBGRBQ { cout << "fuck 8u!" << endl; }
// i just hope my death makes more cents than my life.
using namespace std;
const int maxn=2e4+10;
int n, sc[maxn][4], pm[maxn], psc[maxn][4];
inline int gpts(int ind) {
	return psc[ind][1]+psc[ind][2]+psc[ind][3];
}
inline void restore(int ind) {
	psc[ind][1] = sc[ind][1];
	psc[ind][2] = sc[ind][2];
	psc[ind][3] = sc[ind][3];
}
inline bool lsthan(int x, int y) {
	// cout << "comparing " << x << " " << y << endl;
	int gptsx=gpts(x);
	int gptsy=gpts(y);
	if(gptsx==gptsy) return x>y;
	return gptsx<gptsy ;
}
signed main() {
	while(cin >> n && n!=0) {
		for(int i=1; i<=n; i++) { cin >> sc[i][1] >> sc[i][2] >> sc[i][3]; restore(i); }

		for(int i=1; i<=n; i++) cin >> pm[i];
		int last=pm[1];
		for(int i=2; i<=n; i++) {
			int nowp=pm[i];
			// cout << nowp << " " << last << ", " << gpts(nowp) << " " << gpts(last) << endl;
			if(lsthan(nowp, last)) continue;

			// 以下部分可以预处理
			//TODO 没调精度（输入时乘一百后加个10^(-6)，输出时除回去）

			// 不删
			if(lsthan(nowp, last)) goto NEXT;
			// else cout << nowp << ">=" << last << endl;

			// 尝试最多删一个：
			for(int j=1; j<=3; j++) {
				psc[nowp][j]=0;
				// cout << "deleting " << j << endl;
				if(lsthan(nowp, last)) {
					sc[nowp][j]=0;
					goto NEXT;
				}
				restore(nowp);
			}

			// 尝试最多删两个：
			for(int v=1; v<=3; v++) {
				for(int j=v; j<=3; j++) {
					if(v==j) continue;
					// cout << "deleting " << v << " " << j << endl;
					psc[nowp][j]=psc[nowp][v]=0;
					if(lsthan(nowp, last)) {
						sc[nowp][j]=psc[nowp][v]=0;
						goto NEXT;
					}
					restore(nowp);
				}
			}

			// 尝试全删了			
			psc[nowp][1]=psc[nowp][2]=psc[nowp][3]=0;


			// for(int maxdel=1; maxdel<=3; maxdel++) { // 最多删掉多少个
			// 	for(int j=1; j<=maxdel; j++) {
			// 		psc[nowp][j]=0;
			// 		if(gpts(nowp)<gpts(last)) {
			// 			// ok.
			// 			sc[nowp][j]=0;
			// 			goto NEXT;
			// 		}
			// 	}
			// 	restore(nowp);
			// 	for(int j=maxdel; j>=1; j--) {
			// 		psc[nowp][j]=0;
			// 		if(gpts(nowp)<gpts(last)) {
			// 			// ok.
			// 			sc[nowp][j]=0;
			// 			goto NEXT;
			// 		}
			// 	}
			// 	restore(nowp);
			// }


			NEXT: {
				if(!lsthan(nowp, last)) {
					cout << "No solution" << endl;
					// for(int i=1; i<=n; i++) cout << i << ": " << sc[i][1] << " " << sc[i][2] << " " << sc[i][3] << endl;
					goto EXIT;
				}
				last=nowp;
			}
		}
		// cout << max(sc[last][1], max(sc[last][2], sc[last][3])) << endl;
		// for(int i=1; i<=n; i++) cout << i << ": " << sc[i][1] << " " << sc[i][2] << " " << sc[i][3] << endl;
		
		cout << sc[last][1]+sc[last][2]+sc[last][3] << endl;
		EXIT:;
	}
	return 0;
}