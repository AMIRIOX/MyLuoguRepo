#include <bits/stdc++.h>
using namespace std;
int s1, s2, s3;
int mem[17000];
int main() {
    cin >> s1 >> s2 >> s3;
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                //int sum = i+j+k;
                mem[i+j+k]++;
            }
        }
    }
    int maxn = 0;
    for(int i=5;i<s1*s2*s3;i++){
        if(mem[i]!=0 && mem[i]>mem[maxn])
            maxn = i;
    }
    cout << maxn;
    system("pause");
    return 0;
}