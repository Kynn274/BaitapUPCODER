#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <sstream>

using namespace std;
long long N,Q;
long long a[100001],b[100001];
long long people[100001];
long long gr[100001];
long long sl=0;
long long _min=1;
long long _max=1;
int main(){
	cin>>N>>Q;
	if(N<=1){
		cout<<0;
		return 0;
	}
	
	if(Q==0){
		cout<<0;
		return 0;
	}
	
	for(long long i=0; i<Q; i++) cin>>a[i]>>b[i];
	for(long long i=0; i<N; i++){
		people[i]=-1;
		gr[i]=0;
	}
	for(long long i=0; i<Q; i++){
		bool check=false;
		if(a[i]!=b[i]){
		    if(people[a[i]-1]==-1 && people[b[i]-1]==-1){
		    	people[a[i]-1]=sl;
		    	people[b[i]-1]=sl;
		    	gr[sl]+=2;
		    	check=true;
		    	//cout<<"TH1: \n"<<sl<<' '<<gr[sl]<<endl<<endl;
		    	sl++;
		    }		
		
		    if(people[a[i]-1]==-1 && people[b[i]-1]!=-1 && check==false){
		    	people[a[i]-1]=people[b[i]-1];
		    	gr[people[b[i]-1]]++;
		    	//cout<<"TH2: \n"<<people[b[i]-1]<<' '<<gr[people[b[i]-1]]<<endl<<endl;
		    	check=true;
		    }
		
		    if(people[a[i]-1]!=-1 && people[b[i]-1]==-1 && check==false){
		    	people[b[i]-1]=people[a[i]-1];
		    	gr[people[a[i]-1]]++;
		    	//cout<<"TH3: \n"<<people[a[i]-1]<<' '<<gr[people[a[i]-1]]<<endl<<endl;
		    	check=true;
		    }
		
		    if(people[a[i]-1]!=-1 && people[b[i]-1]!=-1&&check==false){
		    	if(people[a[i]-1]!=people[b[i]-1]){
		    		long long tmp,tmp1;
		    		if(people[a[i]-1]<people[b[i]-1]){
		    			tmp=people[a[i]-1];
		    			tmp1=people[b[i]-1];
		    		}
		    		else{
		    			tmp=people[b[i]-1];
		    			tmp1=people[a[i]-1];
		    		}
		    		for(long long j=0; j<N; j++){
		    			if(people[j]==tmp1){
		    				people[j]==tmp;
		    			}
		    		}
		    		gr[tmp]+=gr[tmp1];
		    		gr[tmp1]=0;
		    		check=true;
		    	}
		    }
		    	//cout<<"TH4: \n"<<tmp<<' '<<tmp1<<endl;
		    	//cout<<gr[tmp]<<' '<<gr[tmp1]<<endl<<endl;
		    }
		    long long tong=0;
		    for(long long i=0; i<sl; i++){
		    	if(gr[i]>_max) _max=gr[i];
		    	tong+=gr[i];
		    }
		    //cout<<"max: "<<_max<<endl;
		    /**** CAN XU LY SO LON PHAN TONG 
		    if(tong==N){
		    	_min=gr[0];
		    	for(long long i=1; i<sl; i++){
		    		if(_min>gr[i]&&gr[i]>1) _min=gr[i];
		    	}
		    }
		    //cout<<"min: "<<_min<<endl;
		    cout<<_max-_min<<endl;
	    }
	/*cout<<endl;
	for(int i=0; i<N; i++){
		cout<<people[i]<<endl;
	}
	cout<<endl;
	for(int i=0; i<N; i++){
		cout<<gr[i]<<endl;
	}*/
}


