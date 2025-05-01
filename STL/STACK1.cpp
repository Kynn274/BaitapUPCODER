#include <bits/stdc++.h>
using namespace std;

int main(){
    char x;
    stack<char> s;
    int a=0;
    while(cin>>x){
        if(x<=90 && x>=65 || 97<=x && x<=122 && x!='*'){
            s.push(x);
            a++;
        }
        if(x=='*' && a>0){
            cout<<s.top();
            s.pop();
            a--;
        }
    }
    return 0;
}
