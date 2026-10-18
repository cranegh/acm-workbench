#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<string>
#include<stack>

using namespace std;
using ll = long long;

const int N = 2e5+9;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll n1[N],n2[N],n3[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;

    string s; cin>>s;

    stack<pair<char,int>> st;
    vector<pair<int,int>> ans;

    ll neatness=-1e18;
    int best_l=0,best_r=0;

    for(int i=0 ; i<2*n ; i++){

        if(i!=0) n1[i]+=n1[i-1];
        if(i!=0) n2[i]+=n2[i-1];
        if(i!=0) n3[i]+=n3[i-1];

        if(s[i]=='('){
            n1[i]+=1;
            st.push({s[i],i});
        }else if(s[i]=='['){
            n2[i]+=1;
            st.push({s[i],i});
        }else if(s[i]=='{'){
            n3[i]+=1;
            st.push({s[i],i});
        }


        if(s[i]==')'){
            int cur=st.top().second;
            st.pop();
            ans.push_back({cur,i});
        }else if(s[i]==']'){
            int cur=st.top().second;
            st.pop();
            ans.push_back({cur,i});
        }else if(s[i]=='}'){
            int cur=st.top().second;
            st.pop();
            ans.push_back({cur,i});
        }
    }

    for(int i=0 ; i<ans.size() ; i++){
        ll same=0,diff=0;

        int l=ans[i].first;
        int r=ans[i].second;

        if(s[r]==')'){
            same += (n1[r-1]-n1[l]);
            diff += (n2[r-1]-n2[l]);
            diff += (n3[r-1]-n3[l]);
        }else if(s[r]==']'){
            same += (n2[r-1]-n2[l]);
            diff += (n1[r-1]-n1[l]);
            diff += (n3[r-1]-n3[l]);
        }else if(s[r]=='}'){
            same += (n3[r-1]-n3[l]);
            diff += (n2[r-1]-n2[l]);
            diff += (n1[r-1]-n1[l]);
        }

        ll cur_n=same-diff;

        if(cur_n>neatness){
            neatness=cur_n;
            best_l=l+1;
            best_r=r+1;
        }else if(cur_n == neatness){
            if(l+1<best_l){
                best_l=l+1;
                best_r=r+1;
            }
        }
    }

    cout<<neatness<<' '<<best_l<<' '<<best_r;

    return 0;
}