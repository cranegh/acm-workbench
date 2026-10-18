#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> a(2*n);
    int x=-1,y=-1;
    
    for(int i=0 ; i<2*n ; i++){
        cin>>a[i];
        if(a[i]==0){
            if(x==-1) x=i;
            else y=i;
        }
    }
    //cout<<x<<" "<<y<<'\n';
    
    vector<bool> check1(n,false);
    
    for(int len=1 ; ; len++){
        int l=x-len;
        int r=x+len;

        if(l<0 || r>=2*n) break;

        if(a[l]==a[r]) check1[a[l]]=true;
        else break;
    }

    int mex1=n;
    for(int i=1 ; i<n ; i++){
        if(!check1[i]){
            mex1=i;
            break;
        }
    }
    
    vector<bool> check2(n,false);

    for(int len=1 ; ; len++){
        int l=y-len;
        int r=y+len;

        if(l<0 || r>=2*n) break;

        if(a[l]==a[r]) check2[a[l]]=true;
        else break;
    }

    int mex2=n;
    for(int i=1 ; i<n ; i++){
        if(!check2[i]){
            mex2=i;
            break;
        }
    }

    vector<bool> check3(n,false);

    bool pp=true;
    for(int len=1 ; ; len++){
        int l=x+len;
        int r=y-len;

        if(r-l<0) break;

        //cout<<l<<" "<<r<<" "<<a[l]<<" "<<a[r]<<'\n'; 
        if(a[l]==a[r]) check3[a[l]]=true;
        else{
            pp=false;
            break;
        }

    }

    int mex3=1;

    if(pp){
        for(int len=1 ; ; len++){
            int l=x-len;
            int r=y+len;

            if(l<0 || r>=2*n) break;

            if(a[l]==a[r]) check3[a[l]]=true;
            else{
                break;
            }
        }

        mex3=n;
        for(int i=1 ; i<n ; i++){
            if(!check3[i]){
                mex3=i;
                break;
            }
        }

    }


    int ans=max({mex1,mex2,mex3});

    cout<<ans;
    cout<<'\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    for(int i=1 ; i<=_ ; i++){
        solve();
    }

    return 0;
}