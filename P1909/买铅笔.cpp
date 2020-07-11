#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main(){
	int resultPrice = INT_MAX;
	int Pencil = 0;
    int slnBudget[5];  //每种铅笔要花的钱 
    vector<int> slnNum;     //
    vector<int> slnPrice;
    int tmp;
    
    cin >>  Pencil;
    for(int i=1; i<=6; i++){
        if(i==1 || i%2 != 0){
            cin >> tmp;
			slnNum.push_back(tmp);
        }else{
            cin >> tmp;
            slnPrice.push_back(tmp);
        }
   }
    
    vector<int>::iterator iNum = slnNum.begin();
	vector<int>::iterator iPrice = slnPrice.begin();
	
	for(int i=1; iNum!=slnNum.end() && iPrice!=slnPrice.end(); i++,iNum++,iPrice++){
		if((*iNum) >= Pencil){
			slnBudget[i] = 1;
		}else{
			slnBudget[i] = Pencil / (*iNum);
			if(Pencil%(*iNum)!=0){
				(slnBudget[i])++;
			}
		}
	}
	
	// To calculation the Price
	// should: slnPrice[i]*slnBudget[i+1];
	for(int i=0; i<3; i++){
		if(slnPrice[i]*slnBudget[i+1] < resultPrice){
			resultPrice = slnPrice[i]*slnBudget[i+1];
		}
	}
	cout << resultPrice;
	
	/*for(int i=1; i<=3; i++)
		cout << slnBudget[i] << " ";
	cout << "Pencil Sum: " << Pencil << endl;
	for(;iNum != slnNum.end() && iPrice != slnPrice.end();iNum++,iPrice++){
		cout << "Num:  " << *iNum << " ";
		cout << "Price: " << *iPrice << " ";
		cout <<endl;
	}*/
	
	
    return 0;
}
