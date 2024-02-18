#include <iostream>
#include <vector>
using namespace std;

int main(){
	long long r,m,n,tmp;
	cin>>r>>m>>n;
	vector<long long> a,c,t;
	vector<vector<long long> >b,d;
	for(long long i=0; i<m; i++){
		cin>>tmp;
		a.push_back(r-tmp);
	}
	for(long long i=0; i<m; i++){
		b.push_back(t);
		cin>>tmp;
		for(long long j=0; j<a[i];j++){
			b[i].push_back(0);
		}
		for(long long j=a[i]; j<r;j++){
			b[i].push_back(tmp);
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<r; j++){
			cout<<b[i][j]<<' ';
		}
		cout<<endl;
	}
	for(long long i=0; i<n; i++){
		cin>>tmp;
		c.push_back(tmp);
	}
	for(long long i=0; i<n; i++){
		d.push_back(t);
		cin>>tmp;
		for(long long j=0; j<c[i];j++){
			d[i].push_back(tmp);
		}
		for(long long j=c[i]; j<r;j++){
			d[i].push_back(0);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<r; j++){
			cout<<d[i][j]<<' ';
		}
		cout<<endl;
	}
	long long max=0,tong;
	for(long long i=0; i<r; i++){
		tong=0;
		for(long long j=0; j<m; j++){
			tong+=b[j][i];
		}
		for(long long j=0; j<n; j++){
			tong+=d[j][i];
		}
		if(tong>max) max=tong;
	}
	cout<<max;
}
/*
#include <iostream>
#include <vector>
using namespace std;

long long main(){
	long long r,m,n,tmp;
	cin>>r>>m>>n;
	vector<long long> a;
	vector<long long> b;
	vector<long long> c;
	vector<long long> d;
	for(long long i=0; i<m; i++){
		cin>>tmp;
		a.push_back(tmp);
	}
	for(long long i=0; i<m; i++){
		cin>>tmp;
		b.push_back(tmp);
	}
	for(long long i=0; i<n; i++){
		cin>>tmp;
		c.push_back(r-tmp);
	}
	for(long long i=0; i<n; i++){
		cin>>tmp;
		d.push_back(tmp);
	}

	vector<vector<long long> > v;
	vector<long long> t;

	for(long long i=0; i<m; i++){
		for(long long j=0; j<r; j++){
			v.push_back(t);
			if(j+1<=a[i])v[i].push_back(b[i]);
			else v[i].push_back(0);
		}
	}
	for(long long i=m; i<m+n; i++){
		for(long long j=0; j<r; j++){
			v.push_back(t);
			if(j+1>c[i-m])v[i].push_back(d[i-m]);
			else v[i].push_back(0);
		}
	}
	/*for(long long i=0; i<m+n; i++){
		for(long long j=0; j<r; j++){
			cout<<v[i][j]<<' ';
		}
		cout<<endl;
	}
	long long max=0;
	for(long long i=0; i<r; i++){
		long long tong=0;
		for(long long j=0; j<m+n; j++){
			tong+=v[j][i];
		}
		if(tong>max) max=tong;
	}
	cout<<max;
}


#include <iostream>
#include <vector>
using namespace std;

long long main(){
	long long r,m,n,tmp;
	cin>>r>>m>>n;
	vector<long long> a,b,c,d;
	for(long long i=0; i<m; i++){
		cin>>tmp;
		a.push_back(tmp);
	}
	for(long long i=0; i<m; i++){
		cin>>tmp;
		b.push_back(tmp);
	}
	for(long long i=0; i<n; i++){
		cin>>tmp;
		c.push_back(r-tmp);
	}
	for(long long i=0; i<n; i++){
		cin>>tmp;
		d.push_back(tmp);
	}

	vector<vector<long long> > v;
	vector<long long> t;
	for(long long i=0; i<m+n; i++) v.push_back(t);
	if(m>n){
		for(long long i=0; i<m; i++){
		for(long long j=0; j<r; j++){
			if(j+1<=a[i])v[i].push_back(b[i]);
			else v[i].push_back(0);
			if(i<n){
				if(j>=c[i])v[i+m].push_back(d[i]);
				else v[i+m].push_back(0);
			}
		}
	}
	}else{
		for(long long i=0; i<n; i++){
		for(long long j=0; j<r; j++){
			if(j>=c[i])v[i].push_back(d[i]);
			else v[i].push_back(0);
			if(i<m){
				if(j+1<=a[i])v[i+n].push_back(b[i]);
				else v[i+n].push_back(0);
			}
		}
	}
	}	
	long long max=0;
	for(long long i=0; i<r; i++){
		long long tong=0;
		for(long long j=0; j<m+n; j++){
			tong+=v[j][i];
		}
		if(tong>max) max=tong;
	}
	cout<<max;
}
*/
