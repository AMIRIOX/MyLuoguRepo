// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// string word, senten;
// int cnt, ansp, ans;
// signed main() {
// 	freopen("in.txt", "r", stdin);
// 	cin >> word;
// 	transform(word.begin(), word.end(), word.begin(),::tolower);
// 	while(cin >> senten) {
// 		transform(senten.begin(), senten.end(), senten.begin(), ::tolower);
// 		if(word==senten) {cnt++; if(cnt==1) ans=ansp;}
// 		ansp = ansp + senten.length() + 1;
// 	}
// 	if(!cnt) cout << -1 << endl; else cout << cnt << " " << ans;
// 	return 0;
// }


#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string word, senten;
int cnt, ans;
signed main() {
	// freopen("in.txt", "r", stdin);
	cin >> word; getchar();
	transform(word.begin(), word.end(), word.begin(),::tolower);
	getline(cin, senten);
	transform(senten.begin(), senten.end(), senten.begin(), ::tolower);
	for(int i=0; i<senten.length(); i++) {
		int wordind=0;
		if(word[wordind]==senten[i] && (i==0 || senten[i-1]==' ') && senten.length()-i>=word.length() && senten[i+word.length()]==' ') {
			bool ok = true;
			for(int j=i; j<i+word.length(); j++) if(senten[j]!=word[wordind++]) {ok=false; continue;}
			if(!ok) continue; if(!cnt) ans=i;
			cnt++;
		}
	}
	if(!cnt) cout << -1 << endl; else cout << cnt << " " << ans;
	return 0;
}

