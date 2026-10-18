#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 35;
int l[N], r[N], ans[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int d,sum; cin>>d>>sum;
    for(int i=1; i<=d; i++){
        cin>>l[i]>>r[i];
    }

    int mn = 0, mx = 0;
    for(int i=1; i<=d; i++){
        mn += l[i];
        mx += r[i];
    }

    for(int i=1; i<=d; i++) ans[i] = l[i];
    int remain = sum;
    for(int i=1; i<=d; i++) remain -= ans[i];

    if(mn <= sum && sum <= mx){
        cout<<"YES\n";
        for(int i=1; i<=d; i++){
            if(remain > 0){
                int cur = min(remain,r[i]-l[i]);
                remain -= cur;
                ans[i] += cur;
            }
        }
        for(int i=1; i<=d; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }
    else{
        cout<<"NO\n";
    }

    

    return 0;
}