#include<iostream>
using namespace std;
const int N = 1e6+9;
int a[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,A,B; cin>>n>>A>>B;
    
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    int ans=0;
    for(int i=1 ; i<=n ; i++){
        if(A*(a[i]-a[i-1])>B) ans+=B;
        else ans+=A*(a[i]-a[i-1]);
    }

    cout<<ans;
    return 0;
      

}
