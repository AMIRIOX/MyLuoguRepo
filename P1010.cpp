// #include <iostream>
// #include <string>
// #include <cstdio>
// #include <bits/stdc++.h>
// using namespace std;
// //#define int long long
// string out;
// int read(){
//     int val=0;
//     int flg=1;
//     char ch = (char)getchar();
//     while(ch<'0'||ch>'9'){
//         if(ch=='-') flg=0;
//         ch = (char) getchar();
//     }
//     while(ch>='0' && ch<='9') {
//         val = (val << 1)+(val << 3) + (ch^48);
//         ch = (char)getchar();
//     }
//     return (flg?val:~(val-1));
// }
// int pow(int a, signed b) {
//     int res=1;
//     for (int i = 0; i < b; i++) {
//         res *= a;
//     }
//     return res;
// }
// void f(int n) {
//     //cout << "?";
//     int small = 0; int power=0;
//     for (int ind = 0; ;ind++) {
//         int t = pow(2,ind);
//         cout << small << " " << power <<" " << t<< endl;
//         if (t <= n) {
//             small = ind;
//             power=t;
//             break;
//         } else {
//             break;
//         }
//     }
//     // if (small == 1 || small == 0) {
//     //     if (small == 0) {
//     //         out += "2(";
//     //         out += to_string(0);
//     //         out += ")";
//     //     } else {
//     //         out += "2";
//     //     }
//     // } else {
//     //     out += "2(";
//     //     f(small);
//     //     out += ")";
//     // }
//     // if (power < n) {
//     //     out += "+";
//     //     f(n - power);
//     // }
// }
// signed main() {
//     int ni;
//     ni = read();
//     cout << ni;
//     f(ni);
//     printf("%s", out.c_str());
//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;
//#define int long long
string out;

int pow(int a, signed b) {
    int res = 1;
    for (int i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}
signed findTheSmallest(int l, int n) {
    int res = 0;
    for (int ind = 0;; ind++) {
        if (pow(l, ind) <= n)
            res = ind;
        else
            break;
    }
    return res;
}
void f(int n) {
    int small = findTheSmallest(2, n);
    int power = pow(2, small);
    if (small == 1 || small == 0) {
        if (small == 0) {
            out += "2(";
            out += to_string(0);
            out += ")";
        } else {
            out += "2";
        }
    } else {
        out += "2(";
        f(small);
        out += ")";
    }
    if (power < n) {
        out += "+";
        f(n - power);
    }
}
signed main() {
    int ni;
    cin >> ni;
    f(ni);
    cout << out;
    return 0;
}