#include <iostream>
using namespace std;
int xa[250],xb[250];
int cmp(int a,int b){
	//如果a胜于b,返回1,平局0,败于-1
	if(a==b)return 0;
	switch (a) {
		case 0:{
			if(b==1 || b==4) return -1;
			else return 1;
		}
		case 1:{
			if(b==2 || b==4) return -1;
			else return 1;
		}
		case 2:{
			if(b==0 || b==3) return -1;
			else return 1;
		}
		case 3:{
			if(b==0 || b==1) return -1;
			else return 1;
		}
		case 4:{
			if(b==2 || b==3) return -1;
			else return 1;
		}
	}
	return 0;
}
int main(int argc, char const *argv[]) {
	int n,na,nb,cnt1=0,cnt2=0;
	cin >> n >> na >> nb;
	for (size_t i = 0; i < na; i++) {
		cin >> xa[i];
	}
	for (size_t i = 0; i < nb; i++) {
		cin >> xb[i];
	}
	for(size_t i=0,cura=0,curb=0;i<n;i++){
		if(cura>=na)cura=0;
		if(curb>=nb)curb=0;
		int flag = cmp(xa[cura],xb[curb]);
		//cout << i <<": "<<xa[cura]<<" "<<xb[curb]<<" "<< flag << endl;
		if(flag==1){
			cnt1++;
		}else if(flag==-1){
			cnt2++;
		}/*else{
			//continue;
			//wdnmd,就他妈这出问题,debug一晚上,草
		}*/
		//cout << flag <<" "<< cnt1 <<" "<< cnt2 << endl;
		cura++,curb++;
	}
	cout << cnt1 <<" "<< cnt2;
	// for(int i=0;i<=4;i++){
	// 	for(int j=0;j<=4;j++){
	// 		std::cout << i << " vs " << j << ": " << std::endl;
	// 		std::cout << cmp(i,j) << std::endl;
	// 	}
	// }
	return 0;
}



// #include <iostream>
//  #include <cstdio>
//  using namespace std;
//  int cmp(int i,int j){
// 	 int ans=0,bns=0;
// 	 if(i==0&&j==1)bns++;
// 	 if(i==0&&j==2)ans++;
// 	 if(i==0&&j==3)ans++;
// 	 if(i==0&&j==4)bns++;
// 	 if(i==1&&j==0)ans++;
// 	 if(i==1&&j==2)bns++;
// 	 if(i==1&&j==3)ans++;
// 	 if(i==1&&j==4)bns++;
// 	 if(i==2&&j==0)bns++;
// 	 if(i==2&&j==1)ans++;
// 	 if(i==2&&j==3)bns++;
// 	 if(i==2&&j==4)ans++;
// 	 if(i==3&&j==0)bns++;
// 	 if(i==3&&j==1)bns++;
// 	 if(i==3&&j==2)ans++;
// 	 if(i==3&&j==4)ans++;
// 	 if(i==4&&j==0)ans++;
// 	 if(i==4&&j==1)ans++;
// 	 if(i==4&&j==2)bns++;
// 	 if(i==4&&j==3)bns++;
// 	 if(ans>bns) return 1;
// 	 else if(ans<bns)return -1;
// 	 else return 0;
//  }
//  int main(){
// 	 int n,na,nb,x,y,xa[201],xb[201],i,j,a,ans,bns;
// 	 for(int i=0;i<=4;i++){
//  		for(int j=0;j<=4;j++){
// 			std::cout << i << " vs " << j << ": " << std::endl;
//  			std::cout << cmp(i,j) << std::endl;
//  		}
//  	}
//
// 	 //0——剪刀    1——石头    2——布     3——蜥蜴人     4——斯波克
// 	 return 0;
// }
