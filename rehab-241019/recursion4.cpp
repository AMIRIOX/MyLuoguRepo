#include <bits/stdc++.h>
using namespace std;

long long ans = 0;

int next_smaller_dollar(int p){
    if(p == 100) return 50;
    else if(p == 50) return 20;
    else if(p == 20) return 10;
    else if(p == 10) return 5;
    else if(p == 5) return 1;
    else return 0;
}

int split(int n, int p) {
    if(!n) return 1;
    else if(n < 0 || !p) return 0;
    else return split(n - p, p) + split(n, next_smaller_dollar(p));
}

signed main() {
    int n;
    cin >> n;
    cout << split(n, 100) << endl;
    return 0;
}
