#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<functional>
#include<map>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    priority_queue< ll,vector<ll>,greater<ll> > pq;

    int n; cin>>n;
    for(int i=0 ; i<n ; i++){
        ll temp; cin>>temp;
        pq.push(temp);
    }

    ll ans=0;
    while(pq.size()>=2){
        ll cur1=pq.top(); pq.pop();
        ll cur2=pq.top(); pq.pop();

        ll cur=cur1+cur2;
        ans+=cur;
        pq.push(cur);
    }

    cout<<ans;


    return 0;
}