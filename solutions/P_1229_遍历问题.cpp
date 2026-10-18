#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s1,s2; cin>>s1>>s2;

    ll ans=0;
    for(int i=0 ; i<s1.length()-1 ; i++){
        char fa = s1[i];
        char child = s1[i+1];
        
        int fa_pos=s2.find(fa);
        int child_pos=s2.find(child);

        if(fa_pos==child_pos+1) ans++;
    }

    cout<<(1<<ans);
    
    return 0;
}