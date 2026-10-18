#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int tt)
{
    int x; cin>>x;
    int ans=1;
    if(x%2==0){
        if(x==6) ans=-1;
        else if(x%4==0) ans=2;
        else{
            if(x%3==0) ans=2;
            else if(x%3==1){
                if((x/3-1)%3==0) ans=4;
                else ans=3;
            }else if(x%3==2){
                if((x/3+2)%3==0) ans=4;
                else ans=3;
            }
        }
    }

    cout<<"Case #"<<tt<<": ";
    cout<<ans<<'\n';

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    for(int i=1 ; i<=_ ; i++) solve(i);

    return 0;
}