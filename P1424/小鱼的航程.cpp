#include <iostream>
using namespace std;
int main(){
	int km = 0;
	int week;
	int after;
	cin >> week >> after;
	
	for(int start = 1; start <= after; start++){
		if(week == 7){
			week = 1;
			cout << "week 7 not swim \n"<<endl;
			continue;
		}
		if(week != 6){
			km += 250;
			cout << "week " << week <<" swim 250,";
			cout <<"now is "<< km <<endl;
		}else{
			cout << "week 6 not swim" << endl;
		}
		week++;
	}
	cout << km;
	return 0;
} 
