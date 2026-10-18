#include<iostream>
#include<deque>

using namespace std;
using ll = long long;

void solve(){
    int n,x,k; cin>>n>>x>>k;
    deque<int> L;
    deque<int> R;
    int mid = (1+n)/2;
    for(int i=1 ; i<mid ; i++) L.push_back(i);
    for(int i=mid ; i<=n ; i++) R.push_back(i);

    k%=2*n;
    for(int i=0 ; i<k ; i++){
        if(x==0){
            L.push_front(R.front());
            R.pop_front();
            R.push_front(L.back());
            L.pop_back();
        }else if(x==1){
            R.push_back(R.front());
            R.pop_front();
        }
        x^=1;
    }

    for(int cur : L) cout<<cur<<" ";
    for(int cur : R) cout<<cur<<' ';
    cout<<'\n';
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;
}
