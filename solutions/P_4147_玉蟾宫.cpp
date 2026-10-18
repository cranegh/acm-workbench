#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>

using namespace std;
using ll = long long;


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;
    vector<int> h(m+2,0);

    int max_s=0;

    for(int i=0 ; i<n ; i++){

        for(int j=1 ; j<=m ; j++){
            char temp; cin>>temp;
            if(temp=='R') h[j]=0;
            else if(temp=='F') h[j]++;
        }

        int top=0;
        vector<int> stk(m+2,0);

        for(int j=1 ; j<=m+1 ; j++){
            while(top>0 && h[j]<h[stk[top]]){
                int cur = h[stk[top--]];
                int l=stk[top];
                int r=j;
                int width=r-l-1;
                max_s=max(max_s,cur*width);
            }
            stk[++top]=j;

        }
    }

    cout<<3*max_s;


    return 0;
}