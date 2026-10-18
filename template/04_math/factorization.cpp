// 试除分解质因数
// 返回 {素因子,指数}；O(sqrt(n))
// n>=1；大整数试除可能超时，适合约 1e12 以内的少量查询
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<pair<ll,int>> factor(ll n){
    vector<pair<ll,int>> ans;
    for(ll i=2 ; n/i>=i ; i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            ans.push_back({i,cnt});
        }
    }
    if(n>1) ans.push_back({n,1});
    return ans;
}
