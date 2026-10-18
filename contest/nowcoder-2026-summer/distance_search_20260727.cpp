#include <bits/stdc++.h>
using namespace std;
int main(){
    const int B=30000;
    int gm=0,gu=0,gn=0;
    vector<int>d(B+1);
    for(int n=2;n<=B;n++){
        d[n]=0;
        for(int i=n-1;i>=1;i--){
            d[i]=gcd(i,n);
            for(int j=i+1;j<n && d[i]>1;j++) d[i]=min(d[i],gcd(i,j)+d[j]);
            if(d[i]>gm) gm=d[i],gu=i,gn=n, cerr<<gm<<' '<<gu<<' '<<gn<<'\n';
        }
    }
}
