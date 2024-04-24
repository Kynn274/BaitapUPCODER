#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <string.h>
#include <stdio.h>
using namespace std;

string findans(stack<int> a, stack<int> b){
  stack<int> memo, ans;
  memo.push(0);
  int tmp;
  while(!a.empty()&&!b.empty()){
    tmp=a.top()+b.top()+memo.top();
    //cout<<tmp<<endl;
    memo.pop();
    a.pop();
    b.pop();
    memo.push(tmp/10);
    ans.push(tmp%10);
  }
  if(memo.top()!=0) ans.push(memo.top());
  string kq="";
  while(!ans.empty()){
    kq=kq+to_string(ans.top());
    ans.pop();
  }
  return kq;
}

int main(){
    vector<string> fibo;
    int n;
    long long m=1000000007;

    fibo.push_back("1");
    fibo.push_back("1");
    cin>>n;
    
    for(int i=2; i<n; i++){
      int len1=fibo[i-2].size();
      int len2=fibo[i-1].size();
  
      if(len1<len2){
        while(len1<len2){
          fibo[i-2].insert(0,"0");
          len1++;
        }
      }else{
        while(len2<len1){
          fibo[i-1].insert(0,"0");
          len2++;
        }
      }
  
      stack<int> a1,b1;
      string tmp="";

      for(int j=0; j<len1; j++){
        tmp.clear();
        tmp=tmp+fibo[i-2][j];
        a1.push(stoi(tmp));
        tmp.clear();
        tmp=tmp+fibo[i-1][j];
        b1.push(stoi(tmp));
      }
      
      fibo.push_back(findans(a1,b1));
    }
    
    while(fibo[n-1][0]=='0'){
      fibo[n-1].erase(0,1);
    }
    cout<<fibo[n-1];
}
