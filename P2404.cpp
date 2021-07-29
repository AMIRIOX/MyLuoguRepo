#include <iostream>
#include <cstdio>
using namespace std;
int n, tmp[1000];
void dfs(int ind, int cnt, int last) {
    if(cnt>n) return;
    if(cnt==n) {
        for(int i=1;i<ind;i++) {
            printf("%d", tmp[i]);
            if(i!=ind-1) printf("+");
        }
        printf("\n");
    }else {
        for(int i=last;i<n;i++) {
            tmp[ind]=i;
            dfs(ind+1, cnt+i, i);
        }
    }
}
int main() {
    scanf("%d", &n);
    dfs(1,0,1);
    return 0;
}