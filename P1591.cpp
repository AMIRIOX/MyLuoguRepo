#include <iostream>
#include <cstdio>
#include <cstring>
using std::cout;
using std::endl;

int ans[100001]={1,1};
char ai[10000],bi[10000];
int as[10000],bs[10000];
int bit(int n){
    int res=0;
    while(n!=0){
        n/=10;
        res++;
    }
    return res;
}

void add(int* a, int* b) {
    int len = ((a[0]>b[0])?a[0]:b[0]);
    for(int i=1;i<=len;i++){
        a[i]+=b[i];
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    len++;
    while(a[len]==0 && len>1)len--;
    a[0]=len;
}
// void multi(int* a, int b){
//     //int g_ys;
//     for(int i=1;i<=100001;i++) {
//         a[i]*=b;
//         a[i+1]+=a[i]/10;
//         a[i]%=10;
//     }
//     a[0]=a[0]+bit(b);
//     while (a[0] > 1 && a[a[0]] == 0) a[0]--;
// }
void multi(int *a, int m) {
    int ys = 0;
    for (int i = 1; i <= a[0]+10; i++) {
        a[i] = a[i] * m + ys;
        ys = a[i] / 10;
        a[i] %= 10;
    }
    a[0] = a[0] + bit(m);
    while (a[0] > 1 && a[a[0]] == 0) a[0]--;
}
void fac(int n){
    for(int i=2;i<=n;i++){
        multi(ans,i);
    }
    //return ans;
}
int main(){
    // scanf("%s",ai);
    // scanf("%s",bi);
    // int ind=1;
    // for(int i=(int)strlen(ai)-1;i>=0;i--){
    //     as[ind++]=ai[i]-'0';
    // }
    // as[0]=ind;
    // ind=1;
    // for(int i=(int)strlen(bi)-1;i>=0;i--){
    //     bs[ind++]=bi[i]-'0';
    // }
    // bs[0]=ind;
    // add(as,bs);
    // for(int i=as[0];i>0;i--){
    //     cout << as[i];
    // }
    int data_n;
    std::cin >> data_n;
    for(int i=0;i<data_n;i++){
        int n,b,cnt=0;
        std::cin >> n >> b;
        memset(ans,0,100001*sizeof(int));
        ans[0]=ans[1]=1;
        fac(n);
        for(int j=ans[0];j>0;j--){
            if(ans[j]==b) cnt++;
            //cout << ans[j];
        }
        //cout << endl;
        cout << cnt<<endl;
    }

    system("pause");
    return 0;
}