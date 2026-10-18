#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    ll tt = 0;
    ll tt_cost = 0;
    int cooking = 0;
    ll first_t = 0;
    ll second_t = 0; 

    for(int i=1 ; i<=n ; i++){
        ll l,t,y; cin>>l>>t>>y;
        tt_cost += l;
        tt = t;

        if(tt >= second_t) cooking = 0;
        else if(tt >= first_t) cooking = 1;
        else cooking = 2;

        //cout<<i<<" "<<tt<<'\n';

        if(cooking<2){
            tt += y;
            cout<<tt<<" ";

            first_t = tt;
            if(first_t>second_t) swap(first_t,second_t);
            
            cooking++;
        }else if(cooking==2){
            tt = first_t;
            tt += y;
            cout<<tt<<" ";

            first_t = tt;
            if(first_t>second_t) swap(first_t,second_t);
        }

    }

    cout<<"\n";
    cout<<tt_cost;
    
    return 0;
}