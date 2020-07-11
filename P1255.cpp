#include <cstdio>
#include <cstring>
#include <iostream>
#define maxn 1000001
using namespace std;

class iNt {
   public:
    int value[maxn];
    iNt() { memset(value, 0, sizeof(value)); }
    iNt operator+(iNt b) {
        iNt tmp;
        int len = value[0] > b.value[0] ? value[0] : b.value[0];
        for (int i = 1; i <= len; i++) {
            tmp.value[i] += value[i] + b.value[i];
            tmp.value[i + 1] += tmp.value[i] / 10;
            tmp.value[i] %= 10;
        }
        len++;
        while (tmp.value[tmp.value[0]] == 0 && tmp.value[0] > 1) len--;
        return tmp;
    }
    void operator=(iNt b) {
        memset(value, 0, sizeof(value));
        memcpy(value, b.value, sizeof(b.value));
    }
    iNt(const iNt& b){
        *this=b;
    }
};

// int n;
// iNt f[maxn];
int main() {
    cout << "what the fuck???";
    // scanf("%d",&n);
    // f[1].value[0]=1;
    // f[1].value[1]=1;
    // f[2].value[0]=1;
    // f[2].value[1]=2;

    // for(int i=3;i<=n;i++)
    //     f[i]=f[i-1]+f[i-2];
    // printf("%lld",f[n]);
    printf("??");
    iNt a;
    a.value[0] = 3;
    a.value[1] = 2;
    a.value[2] = 3;
    a.value[3] = 4;
    iNt b;
    b.value[0] = 4;
    b.value[1] = 2;
    b.value[2] = 3;
    b.value[3] = 4;
    b.value[4] = 5;
    iNt c;
    c = (a + b);
    printf("??");
    cout << c.value[0] << endl;
    for (int i = c.value[0]; i > 0; i--) cout << c.value[i];
    return 0;
}