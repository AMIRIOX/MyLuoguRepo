#include <iostream>
using namespace std;
int a, b, c;
int main() {
    //cin >> a >> b >> c;
    srand((unsigned int)time(0));
    a = rand()%100; b=rand()%100; c=rand()%100;
    if (a > b) {
        if (c > (a - b)) {
            b += (a - b);
            c -= (a - b);
        } else {
            b += c;
            c = 0;
        }
    } else if (a < b) {
        if (c > (b - a)) {
            a += (b - a);
            c -= (b - a);
        } else {
            a += c;
            c = 0;
        }
    }
    a += c / 2;
    b += c / 2;
    c %= 2;
    int i;
    cout << a << ' ' << b << ' ' << c << endl;
    for (i = 1; (a>=i && b>=i); i++) {
        a -= i;
        b -= i;
        // cout << "第" << i << "层楼, a=" << a << ", b=" << b << endl;
        // if(i==5) break;
    }
    cout << (i-1) << endl;
    return 0;
}
//!---------------------------------------------------------
// #include <iostream>
// #include <cstdio>
// using namespace std;
// const int maxn = 100010;

// int main() {

//     return 0;
// }