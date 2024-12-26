#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    
    int hours[14];        //输入的小时数
    int addNum=0;         //add[]的索引
    int add[7];           //add[i]是周i上课的时间
    int unhappyVal=0;    //一周最不开心的值,如果为-1那么没有不开心
    
    //输入小时数字到数组中
	for(int i=0;i<=13;i++){
	    cin >> hours[i];
	    if(i!=0 && ((i%2)!=0 || i==1)){
	        add[addNum++]=hours[i]+hours[i-1];
	    }
	}

	
/*	//把每天的小时加起来(i <= 13 && addNum <= 6可能有Bug)
	for(int i = 0;i <= 13 && addNum <= 6;++i){
	    add[addNum++] = hours[i]+hours[++i];
	}  */ 
	
	int c=-1;
	
	
	
	//找出最不高兴的一天
	for(addNum = 0;addNum <= 6;addNum++){
	    if(add[addNum] > 8 && add[addNum]> add[unhappyVal]){
	        unhappyVal = addNum;
	        c++;
		}
	}
	
	 
	if(c == -1)
	    cout<< "0";
	else
	    cout<< (++unhappyVal);   
    
    return 0;
}
