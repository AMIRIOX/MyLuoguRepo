#include <bits/stdc++.h>
using namespace std;
int Gvo[100000020],W,L;
int main(/*int agrc,int** argv*/){
	char ch = 'W';
	int ind = 0;
	while(ch!='E'){
		ch = getchar();
		if(ch=='W'){
			Gvo[ind++] = 1;
		}else if(ch=='L'){
			Gvo[ind++] = 2;
		}
	} 
	for(int i=0;/*i<ind*/;i++){
		if(Gvo[i]==1)W++; 
		if(Gvo[i]==2)L++;
		if(Gvo[i]==0){
			cout << W <<":"<< L << "\n\n";
			//cout << "??_____";
			break;
		}
		if((W-2>=L || L-2>=W)&&(W>=11 || L>=11)){
			cout << W<<":"<<L<<"\n";
			W=L=0;
		}
	}
	W=L=0;
	for(int i=0;/*i<ind*/;i++){
		if(Gvo[i]==1)W++; 
		if(Gvo[i]==2)L++;
		if(Gvo[i]==0){
			cout << W <<":"<< L <<"\n";
			break;
		}
		if((W-2>=L || L-2>=W)&&(W>=21 || L>=21)){
			cout << W<<":"<<L <<"\n";
			W=L=0;
		}
	}
	system("pause");
	return 0;
} 
