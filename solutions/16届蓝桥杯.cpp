#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

int f(int n,int k){
    if(n==1 && k==1) return 1;
    
    if(k%2==1) return 1-f(n-1,(k+1)/2);
    else return f(n-1,(k+1)/2);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int m; cin>>m;
    for(int i=0 ; i<m ; i++){
        int n,k; cin>>n>>k;
        if(f(n,k)) cout<<"RED\n";
        else cout<<"BLACK\n";
    }

    return 0;
}