#include <iostream>
#include <map>
#include <cctype>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 1e5+10;
char mapping[]={
  '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
};
map<char,int> mapping2 = {
  {'A', 10},
  {'B', 11},
  {'C', 12},
  {'D', 13},
  {'E', 14},
  {'F', 15}
};
// int transTo10b(int x) {
//   // calc the bit of the number
//   int backup=x;
//   int bit = 0;
//   while(backup) {
//     bit++;
//     backup/=10;
//   }
//   if(x==0) bit=1;
//
//   // transform to 16-base number
//   int res = 0;
//   for(int i=0; i<bit; i++) {
//     // 0 1
//     int curbit = x%10;
//     int por = curbit*pow(16, i);
//     res+=por;
//     x/=10;
//   }
//   return res;
// }

int ctoi(char x) {
  if(isdigit(x)) {
    return x-'0';
  }else {
    return mapping2[x];
  }
}
char itoc(int x) {
  return mapping[x];
}

int transTo10b(string v) {
  int bit = v.length();
  int result = 0, zs=0;
  for(int i=v.length()-1;i>=0;i--) {
    result+=ctoi(v[i])*pow(16,zs);
    zs++;
  }
  return result;
}

string transTo16b(int v) {
  if(v==0) {
    return string("00");
  }else {
    vector<int> result;
    string ret;
    while(v){
      result.push_back(v%16);
      v/=16;
    }
    for(int i=result.size()-1;i>=0;i--) {
      ret+=itoc(result[i]);
    }
    return ret;
  }
}

int main() {
  char x;
  cin >> x;
  cout << "#";
  for(int i=1;i<=3;i++) {
    // 字符串拼接 a b
    // 转为10进制
    // 255-去这个数
    // 转为16进制 输出
    char a,b;
    cin >> a >> b;
    string tmp(1,a);
    tmp.push_back(b);
    int i10 = transTo10b(tmp);
    i10=255-i10;
    // cout << i10 << endl;
    cout << transTo16b(i10);
  }
  return 0;
}
