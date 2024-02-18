#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

stack<char> heCoSoMoi(int a, int b){
	stack<char> s;
	switch(b){
		case 0:
			while(a!=0){
				switch(a%2){
					case 1: s.push('1');
					break;
					case 0: s.push('0');
					break;
				}
				a/=2;
			}
		break;
		case 1:
			while(a!=0){
				switch(a%8){
					case 1: s.push('1');
					break;
					case 0: s.push('0');
					break;
					case 2: s.push('2');
					break;
					case 3: s.push('3');
					break;
					case 4: s.push('4');
					break;
					case 5: s.push('5');
					break;
					case 6: s.push('6');
					break;
					case 7: s.push('7');
					break;	
				}
				a/=8;
			}
		break;
		case 2: 
			while(a!=0){
				switch(a%16){
					case 1: s.push('1');
					break;
					case 0: s.push('0');
					break;
					case 2: s.push('2');
					break;
					case 3: s.push('3');
					break;
					case 4: s.push('4');
					break;
					case 5: s.push('5');
					break;
					case 6: s.push('6');
					break;
					case 7: s.push('7');
					break;
					case 8: s.push('8');
					break;
					case 9: s.push('9');
					break;
					case 10: s.push('A');
					break;
					case 11: s.push('B');
					break;
					case 12: s.push('C');
					break;
					case 13: s.push('D');
					break;
					case 14: s.push('E');
					break;
					case 15: s.push('F');
					break;	
				}
				a/=16;
			}
		break;
	}
	return s;
	
}
int main(){
	int a,b;
	cin>>a>>b;
	stack<char> s;
	s=heCoSoMoi(a,b);
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}

