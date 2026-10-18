#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;
using ll = long long;

int main(){

    int n,k; cin>>n>>k;
    deque<int> dq(n);

    for(int i=0 ; i<n ; i++) cin>>dq[i];

    for(int i=1 ; i<=k ; i++){
        if(dq[0]>dq[dq.size()-1]) dq.pop_back();
        else dq.pop_front();
    }

    ll sum=0;
    for(auto &x : dq) sum+=x;
    
    cout<<sum;

    return 0;
}