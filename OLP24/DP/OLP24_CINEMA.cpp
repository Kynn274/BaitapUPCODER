#include <bits/stdc++.h>
#define ll long long
#define fmax 150
using namespace std;

int n, m, k;
int totalLength(0);
int destination;
vector< vector<int> > trippath(1);
vector< vector<int> > tripcity(1);
vector< vector<int> > film_In_Cities;

struct citymap{
    int numOfPaths;
    int paths[fmax][fmax];
};

void getCityMap(citymap & g){
    g.numOfPaths = m;
    memset(g.paths, -1, sizeof g.paths);
    
    int s, e, d;
    for(int i = 0; i < m; i++){
        cin >> s >> e >> d;
        g.paths[s][e] = g.paths[e][s] = d;
    }
}

void binarySearch(int a[], int x, int s, int e){
  int m = (s + e) / 2;
  if(m != s){
    binarySearch (a,x,s,m);
    binarySearch (a,x,m,e);
  }else{
    if(a[m] == x) film_In_Cities[x].push_back(m);
  }
}

int findShortestPath(int s, int e, citymap g){
    int path[fmax];
    int mind(0), minp(s);
    bool check[fmax];

    memset(path, 60, sizeof path);
    memset(check, 0, sizeof check);
    check[s] = 1;
    path[minp] = 0;
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= n; j++)
            if(g.paths[minp][j] != -1)
                path[j] = min(path[j], g.paths[minp][j] + path[minp]);
        for(int j = 1; j <= n; j++)
            if(check[j] == 0){
                mind = path[j];
                minp = j;
                break;
            }
        for(int j = minp; j <= n; j++)
            if(check[j] == 0 && path[j] < mind){
                minp = j;
                mind = path[j];
            }
        if(minp == e) return path[e];
        check[minp] = 1;
        destination = minp;
    }
    return -1;
}

void findShortestTrip(int p, citymap g, int Bom[]){
    if(p != k + 1){
      vector<int> tmp (n + 1, 1e9);
      tripcity.push_back(tmp);
      trippath.push_back(tmp);
      
      for(int i = 0; i < film_In_Cities[Bom[p]].size(); i++){
        for(int j = 0; j < film_In_Cities[Bom[p - 1]].size(); j++){
            int len = findShortestPath(film_In_Cities[Bom[p]][i], film_In_Cities[Bom[p - 1]][j], g);
            trippath[p][film_In_Cities[Bom[p]][i]] = min(trippath[p - 1][film_In_Cities[Bom[p - 1]][j]] + len, trippath[p][film_In_Cities[Bom[p]][i]]); 
            if(trippath[p][film_In_Cities[p][i]] != 1e9) tripcity[p][film_In_Cities[p][i]] = destination;
        }
        cout << trippath[p][film_In_Cities[p][i]] << ' ';
      }
      findShortestTrip(p + 1, g, Bom);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    citymap g;
    int film[fmax];
    int Bom[fmax];
    bool check[fmax];
    
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> film[i];
    getCityMap(g);
    for(int i = 1; i <= k; i++) cin >> Bom[i];
    
    destination = 1;
    film_In_Cities.resize(n + 1);
    film_In_Cities[0].push_back(1);
    
    for(int i = 1; i <= k; i++){
      if(check[Bom[i]] == 0){
        binarySearch(film, Bom[i], 1, n);
        check[Bom[i]] = 1;
      }
    }
    
    vector<int> tmp (n + 1, 1e9);
    tripcity.push_back(tmp);
    trippath.push_back(tmp);
    
    for(int i = 0; i < film_In_Cities[Bom[1]].size(); i++){
        trippath[1][film_In_Cities[Bom[1]][i]] = findShortestPath(1, film_In_Cities[Bom[1]][i], g);
        tripcity[1][film_In_Cities[Bom[1]][i]] = 1;
    }
    findShortestTrip(2, g, Bom);
    
    /*cout << totalLength << '\n';
    for(int i = 0; i < trip.size(); i++)
        cout << trip[i] << ' ';*/

    return 0;
}