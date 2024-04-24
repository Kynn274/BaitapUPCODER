#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int start,end;
	cin>>start>>end;
	double price=0;
	if(start<=end){
		if(end-start<=3){
			price=(end-start)*30000;
		}else{
			price=(3+(end-start-3)*0.7)*30000;
		}
		cout<<price;
	}
}
