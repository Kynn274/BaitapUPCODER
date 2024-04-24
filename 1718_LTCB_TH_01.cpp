#include <iostream>
#include <cmath>
using namespace std;

/*
Biet tuoi cua Anh trai Tèo gap doi tuoi Tèo. Hoi sau k nam thì tuoi cua Tèo và Anh Tèo là bao nhiêu?
Input
gom 2 so nguyên n và k, trong dó n là so tuoi cua Tèo
Output
gom 2 so nguyên cách nhau mot khoang trong lan luot là tuoi cua Tèo và tuoi cua anh trai Tèo sau k nam
*/
int main(){
	int n,k;
	cin>>n>>k;
	cout<<n+k<<' '<<n*2+k;
}
