#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++) cin>>v[i];

    int min_n=110,max_n=0;
    int min_idx=0,max_idx=0;
    for(int i=0 ; i<n ; i++){
        if(v[i]>max_n){ max_n=v[i] ; max_idx=i ;}
        if(v[i]<min_n){ min_n=v[i] ; min_idx=i ;}
    }

    min_idx+=1,max_idx+=1;

    if(min_idx<max_idx) cout<<min_idx<<' '<<max_idx<<' ';
    else cout<<max_idx<<' '<<min_idx<<' ';

    cout<<max_n-min_n;

    return 0;
}
