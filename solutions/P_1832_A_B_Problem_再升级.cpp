#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

vector<int> pri;
const int N = 1e3+9;
ll dp[N];
int n;

bool ispri(int x){
    if(x==1) return false;
    for(int i=2 ; i*i<=x ; i++){
        if(x%i==0) return false;
    }
    return true;
}

void propri(){
    for(int i=1 ; i<=n ; i++){
        if(ispri(i)) pri.push_back(i);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    
    dp[0]=1;
    propri();
    for(int i=0 ; i<pri.size() ; i++){
        for(int j=pri[i] ; j<=n ; j++){
            dp[j]+=dp[j-pri[i]];
        }
    }

    cout<<dp[n];
    
    return 0;
    
}