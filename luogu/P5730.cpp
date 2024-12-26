#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
string output[5]; //要输出的数组
struct junks{}junk;
char operator^(char a,junks b){
    return ((a=='X')?'.':'X');
}
void fillCol(int s,int e,char c){
    for(int i=s;i<=e;i++) 
        output[i]+=c;
}
void fillAlter(){
    for(int i=0;i<5;i++){
        output[i]+=((i%2==0 || i==0)?'X':'.');
    }
}
void fillUpDown(){
    for(int i=0;i<5;i++){
        if(i==0 || i==4){
            output[i]+='X';
        }else
        {
            output[i]+='.';
        }
    }
}
void fillFirst(int cmd,char ch){
    for(int i=0;i<5;i++){
        if(i==cmd){
            output[i]+=ch;
        }else{
            output[i]+=(ch^junk);
        }
    }
}
/*
XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
X.X...X...X...X.X.X.X...X.....X.X.X.X.X
X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
X.X...X.X.....X...X...X.X.X...X.X.X...X
XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX
*/
int main(){
    //freopen("P5730_1.in","r",stdin);
    //freopen("a.out","w",stdout);
    //cout << "???";
    int n,flag=0;
    char c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        c = getchar();
        if(c <'0'||c>'9'){
            i--;
            continue;
        }
        if(flag) fillCol(0,4,'.');
        flag=1;
        if (c == '0'){
            fillCol(0, 4, 'X');
            fillUpDown();
            fillCol(0, 4, 'X');
        }
        if (c == '1'){
            fillCol(0,4,'.');
            fillCol(0,4,'.');
            fillCol(0,4,'X');
        }
        if (c == '2'){
            fillFirst(1,'.');
            fillAlter();
            fillFirst(3,'.');
        }
        if (c == '3'){
            fillAlter();
            fillAlter();
            fillCol(0,4,'X');
        }
        if (c == '4'){
            fillCol(0,2,'X');
            fillCol(3,4,'.');
            fillFirst(2,'X');
            fillCol(0,4,'X');
        }
        if (c == '5'){
            fillFirst(3,'.');
            fillAlter();
            fillFirst(1,'.');
        }
        if (c == '6'){
            fillCol(0,4,'X');
            fillAlter();
            fillFirst(1,'.');
        }
        if (c == '7'){
            fillFirst(0,'X');
            fillFirst(0,'X');
            fillCol(0,4,'X');
        }
        if (c == '8'){
            fillCol(0,4,'X');
            fillAlter();
            fillCol(0,4,'X');
        }
        if (c == '9'){
            fillFirst(3,'.');
            fillAlter();
            fillCol(0,4,'X');
        }
    }
    for(int i=0;i<5;i++){
        cout << output[i] << endl;
    }
    //if(debug) cout << "9 has executed"<<endl;
    system("pause");
    return 0;
}
/*
..X...X.X.X.XXX...X.X.X
..X...X.X.X.X.....X.X.X
..X...X.XXX.XXX...X.XXX
..X...X...X...X...X...X
..X...X...X.XXX...X...X
*/