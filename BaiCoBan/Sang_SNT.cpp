#include <iostream>
using namespace std;

int isPrime[1000000];

void sangSNT(int n){
    for(int i = 0; i <= n; i++)
        isPrime[i] = 1;
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(int i = 2; i * i <= n; i++){
        if(isPrime[i] == 1){
            for(int j = i * i; j <= n; j += i)
                isPrime[j] = 0;
        }
    }
}

int main(){
    ios_base:sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
}