#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool ss(string a, string b){
    string tmp=a+b;
    string tmp1=b+a;
    
    //cout<<tmp<<' '<<tmp1<<endl;
    if(tmp>=tmp1){
      //cout<<"true\n";
      return true;
    }
    else{
      //cout<<"false\n";
      return false;
    } 
}


void merge(vector<string> a, vector<string> b, vector<string> &c){
  int i=0,j=0;
  int len_a=a.size(), len_b=b.size();
  c.clear();
  while(i<len_a && j<len_b){
    if(ss(a[i],b[j])){
      c.push_back(a[i]);
      i++;
    }else{
      c.push_back(b[j]);
      j++;
    }
  }
  while(i<len_a) c.push_back(a[i++]);
  while(j<len_b) c.push_back(b[j++]);
  
  //for(i=0; i<c.size(); i++) cout<<c[i]<<' ';
  //cout<<endl<<endl;
}

void merge_sort(vector<string> & a){
  int s,e,m;
  s=0, e=a.size();
  m=(e+s)/2;

  if(s!=m){
    vector<string> a1;
    vector<string> a2;
    for(int i=s; i<m; i++) a1.push_back(a[i]);
    for(int i=m; i<e; i++) a2.push_back(a[i]);
    merge_sort(a1);
    merge_sort(a2);
    merge(a1,a2,a);
  }
}

int main(){
  int n;
	vector<string> a;
	string tmp;
	ifstream ip("CONNECT.INP");
	ofstream op("CONNECT.OUT");
	
	ip>>n;
	for(int i=0; i<n; i++){
		ip>>tmp;
		while(tmp[0]=='0'&&tmp.size()!=1){
		    tmp.erase(0,1);
		}
		a.push_back(tmp);
		tmp.clear();
	}
	merge_sort(a);
	
	int i=0;
	while(a[i]=="0"&&i!=n-1) i++;
	for(i; i<n; i++){
	    op<<a[i];
	}
	ip.close();
	op.close();
	return 0;
}
