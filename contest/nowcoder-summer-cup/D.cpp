#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    ll cur_t = 0;
    ll tt_cost = 0;
    int cooking = 0;
    int first_t = 0;
    int second_t = 0;

    for(int i=0 ; i<n ; i++){
        ll l,t,y; cin>>l>>t>>y;
        cur_t = t;

        tt_cost += l;

        if(cur_t >= second_t) cooking = 0;
        else if(cur_t >= first_t) cooking = 1;
        else cooking = 2;

        if(cooking<2){
            cur_t += y;

            cooking++;
        }else if(cooking==2){
            cur_t = first_t;
            cur_t += y;
        }
        
        first_t = cur_t;
        if(first_t>second_t) swap(first_t,second_t);

        cout<<cur_t<<" ";

    }

    cout<<'\n';
    cout<<tt_cost;

    
    return 0;
}
