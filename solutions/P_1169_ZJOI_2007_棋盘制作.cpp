#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>

using namespace std;
using ll = long long;

int max_sz=1;
int max_sj=1;

int n,m; 

void clac(const vector<int> &h){
    int top=0;
    vector<int> stk(m+2,0);

    for(int j=1 ; j<=m+1 ; j++){
        while(top>0 && h[j]<h[stk[top]]){
            int cur = h[stk[top--]];
            int l = stk[top];
            int r = j;
            int width=r-l-1;

            max_sj=max(max_sj,width*cur);
            int d=min(width,cur);
            max_sz=max(max_sz,d*d);
        }
        stk[++top]=j;
    }
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    cin>>n>>m;
    
    vector<int> h1(m+2,0);
    vector<int> h2(m+2,0);

    for(int i=1 ; i<=n ; i++){

        for(int j=1 ; j<=m ; j++){
            int temp; cin>>temp;
            if((i+j)%2==1) temp^=1;

            if(temp==1){
                h1[j]++;
                h2[j]=0;
            }else{
                h1[j]=0;
                h2[j]++;
            }
        }

        clac(h1);
        clac(h2);

    }

    cout<<max_sz<<'\n';
    cout<<max_sj<<'\n';


    return 0;
}