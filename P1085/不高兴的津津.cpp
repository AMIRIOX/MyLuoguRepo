#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    
    int hours[14];        //�����Сʱ��
    int addNum=0;         //add[]������
    int add[7];           //add[i]����i�Ͽε�ʱ��
    int unhappyVal=0;    //һ������ĵ�ֵ,���Ϊ-1��ôû�в�����
    
    //����Сʱ���ֵ�������
	for(int i=0;i<=13;i++){
	    cin >> hours[i];
	    if(i!=0 && ((i%2)!=0 || i==1)){
	        add[addNum++]=hours[i]+hours[i-1];
	    }
	}

	
/*	//��ÿ���Сʱ������(i <= 13 && addNum <= 6������Bug)
	for(int i = 0;i <= 13 && addNum <= 6;++i){
	    add[addNum++] = hours[i]+hours[++i];
	}  */ 
	
	int c=-1;
	
	
	
	//�ҳ�����˵�һ��
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
