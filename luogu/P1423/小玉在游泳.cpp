#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	//freopen("in.txt","w",stdout);
    //varible
    double target = 0;
    double step = 2;
    int stepNum = 0;
    
    //algorithms
    cin >> target;
    while(target>0){
    	target -= step;
    	//printf("%f\n",step);
    	step *= 0.98;
    	stepNum++;
    	//printf("%d %f %f\n",stepNum,target,step);
	}
    printf("%d",stepNum);
    return 0;
}
