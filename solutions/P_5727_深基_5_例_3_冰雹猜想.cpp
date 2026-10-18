#include<iostream>
#include<algorithm>
#include<vector>

using ll = long long;
using namespace std;
const int N =1e3+9;
int a[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    vector<int> a;
    int n; cin>>n;
    a.push_back(n);

    while(n!=1){
        if (n%2==0){
            n/=2;
            a.push_back(n);
        }
        else if(n!=1 && n%2){
            n=n*3+1;
            a.push_back(n);
        }
    }

    for (int i=a.size()-1 ; i>=0 ; i--) cout<<a[i]<<' ';

    return 0;
}
