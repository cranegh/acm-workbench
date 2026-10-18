#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

const int N = 2e1+9;
string a[N];
bool cmp(string a,string b);
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for (int i=1 ; i<=n ; i++){
        cin>>a[i];
    }
    
    sort(a+1,a+1+n,cmp);
    
    string ans="";
    for (int i=1 ; i<=n ; i++){
        ans+=a[i];
    }

    cout<<ans;
    return 0;
}
bool cmp(string a,string b){
    return a+b>b+a;
}
