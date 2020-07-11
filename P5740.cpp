#include <bits/stdc++.h>
using namespace std;
struct Student{
    int ind;
    string name;
    int yuwen;
    int shuxue;
    int yingyu;
    bool operator<(const Student o) const{
        int sum1 = yingyu+shuxue+yuwen;
        int sum2 = o.yuwen+o.yingyu+o.shuxue;
        if(sum1==sum2)return ind>o.ind;
        return sum1<sum2;
    }
}stu[1020];
int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        stu[i].ind = i;
        cin >> stu[i].name >> stu[i].yuwen >> stu[i].shuxue >> stu[i].yingyu;
    }
    sort(stu,stu+N);
    cout << stu[N-1].name <<" "<< stu[N-1].yuwen <<" "<< stu[N-1].shuxue <<" "<< stu[N-1].yingyu;
    system("pause");
    return 0;
}