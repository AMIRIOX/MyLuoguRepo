#include <iostream>
using namespace std;
int a[100005];
int main() {
    int n,sum=0;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=1; i<n; i++) if(a[i]>a[i-1]) sum+=a[i]-a[i-1];
    cout  << sum+a[0];
    return 0;
}

// #include <iostream>
// using namespace std;
// int l, r, n, ans;
// int ways[100005];
// bool flg = false;
// /*
//   4 3 2 5 2 5
// */

// void ttz(int a[], int l, int r) {
//     for (int i = l; i < r; i++) {
//         a[i]--;
//     }
// }
// bool check() {
//     for (int i = 0; i < n; i++) {
//         if (ways[i] != 0) return false;
//     }
//     return true;
// }
// int main() {
//     cin >> n;
//     for (int i = 0; i < n; ++i) {
//         cin >> ways[i];
//     }
//     while (flg || !check()) {
//         flg = false;
//         for (int i = l; i < n; ++i) {
//             if (ways[i] != 0)
//                 r++;
//             else {
//                 ans++;
//                 ttz(ways, l, r);
//                 break;
//             }
//         }
//         if (r >= n-1) {
//             l = 0, r = 0;
//             flg = false;
//         } else {
//             l = r + 1;
//             flg = true;
//         }
//         cout << l << " " << r << endl;
//     }
//     cout << endl << "------" << endl;
//     cout << ans;
//     return 0;
// }