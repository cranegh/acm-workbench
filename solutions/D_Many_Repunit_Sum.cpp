#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int N = 4e5+9;
ll cnt[N];
ll d[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int max_len=0;

    int n; cin>>n;
    for(int i=0 ; i<n ; i++){
        int temp; cin>>temp;
        if(max_len<temp) max_len=temp;
        cnt[temp]++;
    }

    ll cur_cnt=0;
    for(int i=max_len ; i>=1 ; i--){
        cur_cnt+=cnt[i];
        d[i]=cur_cnt;
    }

    vector<int> ans;

    ll next=0;
    for(int i=1 ; i<=max_len || next>0 ; i++){
        d[i]+=next;
        next=0;
        int cur=d[i]%10;
        next+=(d[i]-cur)/10;
        ans.push_back(cur);
    }

    for(int i=ans.size()-1 ; i>=0 ; i--) cout<<ans[i];

    return 0;
}