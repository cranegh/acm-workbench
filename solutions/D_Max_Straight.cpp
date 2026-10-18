#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

unordered_map<int,int> mp;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n; cin>>n;

    int ans=0;

    for(int i=0 ; i<n ; i++){
        int temp; cin>>temp;

        if(mp.count(temp-1)==0){
            mp[temp]=1;
        }else mp[temp]=mp[temp-1]+1;

        ans=max(ans,mp[temp]);
    }

    cout<<ans;

    return 0;
}