#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s_fac; cin>>s_fac;
    int N = s_fac.size();
    string S=s_fac;
    for(int i=1 ; i<=N-1 ; i++){
        cin>>s_fac;
        S+=s_fac;
    }

    vector<int> v;
    int cnt_0=0 , cnt_1=0;

    if(S[0]=='1') v.push_back(0);
    
    for(int i=0 ; i<S.size() ; i++){
        if(S[i]=='0'){
            if(cnt_1>0){
                v.push_back(cnt_1);
                cnt_1=0;
            }
            cnt_0++;
        }
        else if(S[i]=='1'){
            if(cnt_0>0){
                v.push_back(cnt_0);
                cnt_0=0;
            }
            cnt_1++;
        }
    }

    if(cnt_0>0) v.push_back(cnt_0);
    if(cnt_1>0) v.push_back(cnt_1);

    cout<<N<<' ';
    for(int i=0 ; i<v.size() ; i++){
        cout<<v[i]<<' ';
    }

    return 0;
}