#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

pair<int,int> t[130];

int qpow[8]={1,2,4,8,16,32,64,128};

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=qpow[n] ; i++){
        int p; cin>>p;
        t[i]={p,i};
    }

    sort(t+1,t+1+qpow[n-1]);
    sort(t+1+qpow[n-1],t+1+qpow[n]);

    if(t[qpow[n-1]].first<=t[qpow[n]].first) cout<<t[qpow[n-1]].second;
    else cout<<t[qpow[n]].second;



}