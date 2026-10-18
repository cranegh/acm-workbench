#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;
using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6+9;

struct w{
    int cnt,fit;
    bool operator < (const w& u) const
    {
        if(cnt==u.cnt) return fit<u.fit;
        else return cnt<u.cnt;
    }
};

unordered_map<int,w> mp; 

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n; cin>>n;

    int guess=1;
    int best_ty=0;
    ll ans=0;

    for(int i=1 ; i<=n ; i++){
        int ty; cin>>ty;

        if(mp.count(ty)==0){
            mp[ty].fit=i;
            mp[ty].cnt=1;
        }else mp[ty].cnt++;

        if(mp[best_ty]<mp[ty]) best_ty=ty;

        if(guess==ty){
            ans++;
        }else{
            guess=best_ty;
        }
    }

    cout<<ans;

    return 0;
}