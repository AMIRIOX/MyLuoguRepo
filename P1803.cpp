#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int sssz = 0;
struct ak {
    int begin;
    int end;
};
bool cmp(ak ioi, ak noi) { return ioi.end <= noi.end; }
int main() {
    ak NOIP[100001];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        cin >> NOIP[i].begin >> NOIP[i].end;
    }
    int ans = 0;
    sort(NOIP, NOIP + n, cmp);
    for (int i = 0; i < n; i++) {
        if(sssz<=NOIP[i].begin){
            ans++;
            sssz = NOIP[i].end;
        }
    }
    printf("%d",ans);
    return 0;
}