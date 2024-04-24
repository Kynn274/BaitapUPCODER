#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct dothi{
	int nV;
	int canh[100][100];
};

int nE,a,b,S,V;
queue<queue<int> > visited;
stack<int> road;

void nhap(dothi&g){
	cin>>g.nV>>nE>>S>>V;
	for(int i=0; i<g.nV; i++)
		for(int j=0; j<g.nV; j++)
			g.canh[i][j]=-2;
	for(int i=0; i<nE; i++){
		cin>>a>>b;
		g.canh[a-1][b-1]=-1;
		g.canh[b-1][a-1]=-1;
	}
}

void duyet(int S, int V, dothi g){
	queue<int> tmp;
	road.push(S);
	int luu=-1;
	while(!road.empty()){
		luu=road.top();
		for(int i=0; i<g.nV; i++){
			if(g.canh[road.top()][i]==-1 ||g.canh[i][road.top()]==-1 ){
				road.push(i);
				tmp.push(i);
				if(road.top()==V){
					visited.push(tmp);
					while(!tmp.empty()) tmp.pop();
					road.pop();
					g.canh[V][road.top()]==-2;
					g.canh[road.top()][V]==-2;
				}
			}
		}
		if(luu==road.top()){
			road.pop();
			g.canh[luu][road.top()]==-2;
			g.canh[road.top()][luu]==-2;
		}
	}
	
}

int main(){
	dothi g;
	nhap(g);
	duyet(S,V,g);
}
