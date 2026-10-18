#include<iostream>
#include<map>

using namespace std;

const int N = 1e5+9;
int ans[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;

    for(int i=1 ; i<=n ; i++) ans[i]=-1;

    map<int,int> ev;
    
    for(int i=0 ; i<n ; i++){
        int l,r; cin>>l>>r;
        ev[l]++;
        ev[r+1]--;
    }

    int cp=0;
    for(auto const& [t,c] : ev){
        cp+=c;

        if(ans[cp]==-1 ) ans[cp]=t;
    }

    for(int k=1 ; k<=n ; k++) cout<<ans[k]<<'\n';

    return 0;
}