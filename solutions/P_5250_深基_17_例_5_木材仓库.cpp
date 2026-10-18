#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>

using namespace std;
using ll = long long; 

int n;
set<int> st;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int q; cin>>q;
    for(int i=0 ; i<q ; i++){
        int op; cin>>op;
        if(op==1){
            int l; cin>>l;
            if(st.find(l)==st.end()) st.insert(l);
            else cout<<"Already Exist\n";
        }else if(op==2){
            int l; cin>>l;

            if(st.empty()){
                cout<<"Empty\n";
                continue;
            }

            auto idx=st.lower_bound(l);

            if(idx==st.end()){
                cout<<*(--idx)<<'\n';
                st.erase(*idx);
            }else if(*idx==l){
                cout<<*idx<<'\n';
                st.erase(*idx);
            }else{
                if(idx==st.begin()){
                    cout<<*idx<<'\n';
                    st.erase(*idx);
                }else{
                    int sh=*(--idx);
                    int lo=*(++idx);
                    if(l-sh<=lo-l){
                        cout<<sh<<'\n';
                        st.erase(sh);
                    }else{
                        cout<<lo<<'\n';
                        st.erase(lo);
                    }
                }
            }
        }
        
    }

    return 0;
}