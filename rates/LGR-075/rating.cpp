// #include <cstdio>
// #include <iostream>
// using namespace std;
// const int maxn = 100010;
// int a, b, c;
// int main() {
//     cin >> a >> b >> c;
//     if (a < b) {
//         while (a != b && c > 0) a++, c--;
//     } else {
//         while (a != b && c > 0) b++, c--;
//     }
//     while (c >= 2) {
//         c -= 2;
//         a++, b++;
//     }
//     int lowCount = 0;
//     while (a >= lowCount + 1 && b >= lowCount + 1) {
//         lowCount++;
//         a-=lowCount; b-=lowCount;
//     }
//     cout << lowCount << endl;
//     return 0;
// }
#include <iostream>
#include <cmath>
#define int long long
using namespace std;
int a,b,c;
signed main(int argc, char const *argv[]) {
	cin >> a >> b >> c;
	if(c>=abs(a-b)) {
		a>b?b+=abs(a-b):a+=abs(a-b);
		c-=abs(a-b);
	}else{
		a>b?b+=c:a+=c;
		c=0;
	}
	a+=c/2; b+=c/2; c/=2;
	register int ans = 0;
	// cout << a << ' ' << b << endl;
	while(a>=ans+1 && b>=ans+1) {
		ans++;
		a-=ans; b-=ans;
	}
	cout << ans << endl;
	return 0;
}
