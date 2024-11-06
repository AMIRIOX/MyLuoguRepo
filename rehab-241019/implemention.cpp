#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
int n;
char a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
char d[maxn][maxn];
bool cmp() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(c[i][j] != b[i][j]) return false;
        }
    }
    return true;
}
bool cmp2() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(d[i][j] != b[i][j]) return false;
        }
    }
    return true;
}
bool rotate90() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            c[j][n - i + 1] = a[i][j];
        }
    }
    return cmp();
}
bool rotate180() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            c[n - i + 1][n - j + 1] = a[i][j];
        }
    }
    return cmp();
} 
bool rotate270() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            c[n - j + 1][i] = a[i][j];
        }
    }
    return cmp();
}
void print() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}
bool reflect() {
    memcpy(c, a, sizeof a);
    for(int j = 1; j <= n / 2; j++) {
        for(int i = 1; i <= n; i++) {
            swap(c[i][j], c[i][n - j + 1]);
        }
    }
    return cmp();
}
bool comb1() {
    reflect();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            d[j][n - i + 1] = c[i][j];
        }
    }
    return cmp2();
}
bool comb2() {
    reflect();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            d[n - i + 1][n - j + 1] = c[i][j];
        }
    }
    return cmp2();
}
bool comb3() {
    reflect();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            d[n - j + 1][i] = c[i][j];
        }
    }
    return cmp2();
}
signed main(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> b[i][j];
        }
    }
    if(cmp()) { cout << 6 << endl;  }
    else if(rotate90()) { cout << 1 << endl;  }
    else if(rotate180()) { cout << 2 << endl;  }
    else if(rotate270()) { cout << 3 << endl;  }
    else if(reflect()) { cout << 4 << endl;  }
    else if(comb1() || comb2() || comb3()) { cout << 5 << endl; }  
    else cout << 7 << endl;
    return 0;
}
