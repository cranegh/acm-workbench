#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int tt_cost = 0;
    int tt_solved = 0;
    for(int i=1 ; i<=8 ; i++){
        int c,t,sta; cin>>c>>t>>sta;
        if(sta==1){
            tt_cost += 20*(c-1)+t;
            tt_solved++;
        }
    }

    cout<<tt_solved<<" ";
    cout<<tt_cost<<'\n';
    
    return 0;
}