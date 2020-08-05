#include <bits/stdc++.h>
using namespace std;
#define fuck return
#define you 0
int ans[100001];
int* t;
int bit(int n){
    int res=0;
    while(n!=0){
        n/=10;
        res++;
    }
    return res;
}
void add(int a[], int b[]) {
    int len = (a[0] > b[0] ? a[0] : b[0]);
    for (int i = 1; i <= len; i++) {
        a[i] += b[i];
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    len++;
    while (len > 1 && a[len] == 0) len--;
    a[0]=len;
}
// 5*2=10               0
// 6*2=12               3
// 4*2=8                9
void mult(int a[], int m) {
    // for (int i = 1; i <= a[0]; i++) {
    // 	for (int j = 1; j <= b[0]; j++) {
    // 		c[i + j - 1] += a[i] * b[j];
    // 		c[i + j] += c[i + j - 1] / 10;
    // 		c[i + j - 1] %= 10;
    // 	}
    // }
    int ys = 0;
    for (int i = 1; i <= 100001; i++) {
        a[i] = a[i] * m + ys;
        ys = a[i] / 10;
        a[i] %= 10;
    }
    a[0] = a[0] + bit(m);
    while (a[0] > 1 && a[a[0]] == 0) a[0]--;
}
int* fac(int n) {
    // if(n==1) return 1;
    int* res = new int[100001]{1, 1};
    for (int i = 2; i <= n; i++) {
        mult(res, i);
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    int ans[100001];
    for (int i = 1; i <= n; i++) {
         t = fac(i);
         add(ans, t);

        // int* result = fac(i);
        // cout << i<<"'s factor is ";
        // for (int i = result[0]; i > 0; i--) cout << result[i];
        // cout << endl;
        // delete[] result;

        // cout << "add i and before is ok";
    }
    // cout << *ans;
    for (int i = ans[0]; i > 0; i--) {
       cout << ans[i];
    }
    //delete[] t;
    system("pause");
    fuck you;
}