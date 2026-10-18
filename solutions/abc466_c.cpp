#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;

    int ans = 0;
    int r = 2;

    for(int i=1 ; i<n ; i++){
        r = max(r,i+1);
        while(r<=n){
            cout<<"? "<<i<<" "<<r<<endl;

            string response; cin>>response;
            if(response == "Yes") r++;
            else break;
        }
        ans += r-1-i;
    }

    cout<<"! "<<ans<<endl;

    return 0;
}
