#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<unordered_map>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int sum=0;
    int mx=-67;
    for(int i=0 ; i<7 ; i++){
        int cur; cin>>cur;
        if(cur>mx) mx=cur;
        sum+=cur;
    }

    sum*=-1;
    sum+=2*mx;

    cout<<sum<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();


    return 0;
}