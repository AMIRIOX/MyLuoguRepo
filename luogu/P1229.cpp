#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 100010
int ans;
char a[MAXN], b[MAXN];
int main(int argc, char const *argv[]) {
    cin >> a >> b;
    for(int i=0;a[i];i++)
        for(int j=1;b[j];j++)
            if(a[i]==b[j] && a[i+1]==b[j-1]) 
                ans++;
    cout << (1<<ans) << endl;
    return 0;
}
