#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bitset>
#include<set>

using namespace std;
using ll = long long;

const int N = 5e5+9;
int cnt[26];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,l,r; cin>>n>>l>>r;
    string s; cin>>s;

    for(int i=l ; i<=min(r,n-1) ; i++){
        cnt[s[i]-'a']++;
    }

    ll ans=0;
    int head=l,tail=r;

    for(int i=0 ; i<n ; i++){
        ans+=cnt[s[i]-'a'];

        if(head<=n-1) cnt[s[head++]-'a']--;
        if(tail+1<=n-1) cnt[s[++tail]-'a']++;
    }

    cout<<ans;

    return 0;
}