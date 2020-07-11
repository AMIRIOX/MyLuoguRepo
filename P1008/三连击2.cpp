#include <iostream>
using namespace std;
struct threeBitNum{
  int f;
  int s;
  int t;
  int operator[](int i){
  	switch(i){
  		case 1: return f;break;
	 	case 2: return s;break;
	 	case 3: return t;break;
	}
  }
  bool selfNotEqual(){
  	if(f!=s && s!=t && f!= t)
  		return 1;
  	else return 0;
  }
  bool operator!=(threeBitNum b){
  	int v=1;
  	if(selfNotEqual() && b.selfNotEqual()){
  		if(f != b.f && s != b.s && t != b.t){
  			if(f!=b.s && f!=b.t && s!=b.f && s!=b.t && t!=b.f && t!=b.s){
  				return true;
			}
			return false;
		}
		return false;
	}
	return false;
  }
};
typedef threeBitNum NUM;
threeBitNum chaiNum(int num){
    threeBitNum ret;
    ret.f = num/100;
    ret.s = (num/10)%10;
    ret.t = num%10;
    return ret;
}
bool unallow(int num){
	threeBitNum x = chaiNum(num);
	if(num > 999 || x.f==0 || x.s==0 ||x.t==0) return true;
	return false;
}
int getNum(int a,int b, int c){
    return a*100+b*10+c;
}
int main(){
    for(int i=1; i<=3; i++){
    	for(int j=1; j<=9; j++){
    		for(int k=1; k<=9; k++){
    			int f = getNum(i,j,k);
    			int s = f*2;
    			int t = f*3;
    			
    			if(unallow(f) || unallow(s) || unallow(t)){
    				continue;
				}
    			
    			NUM ef = chaiNum(f);
    			NUM es = chaiNum(s);
    			NUM et = chaiNum(t);
    			
    			if(ef!=es && es!=et && ef!=et){
    				cout << f << " " << s << " " << t << endl;
				}
			}
		}
	} 
    
    
    return 0;
}
