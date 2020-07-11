#include <bits/stdc++.h>
using namespace std;
int n=0,x=0,arr[15];

const int jc[]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int cantor(){
    int cval=0;
    for(int i=0;i<n;i++){
        int smaller=0;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]) smaller++;
        }
        cval += smaller*jc[n-i-1];
    }
    return cval;
}
void deCantor(){
    vector<int> v;
    vector<int> a;
    for(int i=1;i<=n;i++)
        v.push_back(i);
    for(int i=n;i>=1;i--){
        //cout << i<<endl;
        int ys=x%jc[i-1];
        int shang = x/jc[i-1];
        x=ys;
        sort(v.begin(),v.end());
        a.push_back(v[shang]);
        v.erase(v.begin()+shang);
    }
    for(int i=0;i<a.size();i++){
        cout << a[i]<<" ";
    }
}


int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    x = cantor()-1;
    deCantor();
    system("pause");
    return 0;
}