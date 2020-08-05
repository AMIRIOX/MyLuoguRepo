#include<iostream>
#include<math.h>
using namespace std;
int x[20],n,k;//依照题目所设
bool isprime(int n){//判断是否质数
    int s=sqrt(double(n));
    for(int i=2;i<=s;i++){
        if(n%i==0)return false;
    }
    return true;
}
int rule(int choose_left_num,int already_sum,int start,int end){//choose_left_num为剩余的k，already_sum为前面累加的和，start和end为全组合剩下数字的选取范围；调用递归生成全组合，在过程中逐渐把K个数相加，当选取的数个数为0时，直接返回前面的累加和是否为质数即可
    if(choose_left_num==0)return isprime(already_sum);
    int sum=0;
    for(int i=start;i<=end;i++){
        sum+=rule(choose_left_num-1,already_sum+x[i],i+1,end);
    }
    return sum;
}
int main(){
    cin>>n>>k;
    for(int i =0;i<n;i++)cin>>x[i];
    cout<<rule(k,0,0,n-1);//调用递归解决问题
}
