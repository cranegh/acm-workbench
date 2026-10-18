#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<unordered_map>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

unordered_map<string,bool> mp;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;

    int ans=0;

    for(int i=0 ; i<n ; i++){
        string s; cin>>s;
        if(mp.count(s)==0){
            mp[s]=true;
            ans++;
        }
    }

    cout<<ans;


    return 0;
}