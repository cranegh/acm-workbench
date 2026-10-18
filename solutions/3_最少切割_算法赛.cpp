#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e5+9;
int num[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    string s; cin>>s;
    for(int i=1 ; i<=26 ; i++) num[i]=0;

    for(int i=0 ; i<n ; i++){
        num[s[i]-'a'+1]++;
    }


    for(int i=1 ; i<=26 ; i++) num[i]%=2;
    int ans=1;
    for(int i=1 ; i<=26 ; i++) ans+=num[i];
    if(ans>1) ans-=1;

    cout<<ans;


    
}