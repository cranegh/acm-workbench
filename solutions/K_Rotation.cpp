#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

ll cnt[4];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n; cin>>n;
    for(int i=0 ; i<n ; i++){
        int temp; cin>>temp;
        if(temp==0){
            cnt[3]+=1;
            cnt[2]+=2;
            cnt[1]+=3;
        }else if(temp==1){
            cnt[0]+=1;
            cnt[3]+=2;
            cnt[2]+=3;
        }else if(temp==2){
            cnt[1]+=1;
            cnt[0]+=2;
            cnt[3]+=3;
        }else if(temp==3){
            cnt[2]+=1;
            cnt[1]+=2;
            cnt[0]+=3;
        }
    }

    ll ans=1e7+9;

    for(int i=0 ; i<4 ; i++){
        ll cur_cnt=cnt[i];
        int cur_idx = (i+cur_cnt%4)%4;
        if(cur_idx==0) ans=min(ans,cur_cnt);
        else ans=min(ans,cur_cnt+4-cur_idx);
    }

    cout<<ans;

    return 0;
}