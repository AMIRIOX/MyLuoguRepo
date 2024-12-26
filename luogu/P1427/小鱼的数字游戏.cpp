#include <iostream>
#include <vector>
using namespace std;
int main(){
    int tmp;
    vector<int> v;
    while(cin>>tmp && tmp!=0){
        v.push_back(tmp);
    }
    for(int i=v.size()-1;i>=0;i--){
        cout << v[i];
        if(i != 0) cout <<" ";
    }
    
    return 0;
}
