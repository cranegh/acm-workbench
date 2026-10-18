#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

const int N =5e5+9;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<int> v(n);

    for(int i=0 ; i<n ; i++) cin>>v[i];

    int r=v[0]+0-1;
    int i=1;

    while(i<=r){
        r=max(r,v[i]+i-1);
        if(r>=n){
            r=n-1;
            break;
        }
        i++;
    }

    cout<<r+1;
    
    return 0;
}