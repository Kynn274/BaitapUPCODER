#include <iostream>
#include <queue>
using namespace std;

struct dothi{
	int nV;
	int canh[100][100];
};

int nE;
int S;
int a, b;
queue<int> road;
queue<int> visited;

int ds[100];
int iCount=0;
void nhap(dothi&g){
	cin>>g.nV>>nE>>S;
		
	for(int i=0; i<g.nV; i++)
		for(int j=0; j<g.nV; j++)
			g.canh[i][j]=0;
			
	for(int i=0; i<nE; i++){
		cin>>a>>b;
		g.canh[a-1][b-1]=1;
		g.canh[b-1][a-1]=1;
	}
	
}

bool check_existance(int tmp, queue<int> k){
	while(!k.empty()){
		if(tmp==k.front()) return true;
		k.pop();
	}
	return false;
}

void duyet(int S, dothi g){
	road.push(S-1);
	while(!road.empty()){
		for(int i=0; i<g.nV; i++){
			if(g.canh[road.front()][i]==1 ||g.canh[i][road.front()]==1){
				road.push(i);
				g.canh[road.front()][i]=0;
				g.canh[i][road.front()]=0;
			}
		}
		if(!check_existance(road.front(), visited)) visited.push(road.front());
		road.pop();
	}
}


void xuat(){
	while(!visited.empty()){
		cout<<visited.front()+1<<' ';
		visited.pop();
	}
}
int main(){
	dothi g;
	nhap(g);
	duyet(S,g);
	xuat();
}
