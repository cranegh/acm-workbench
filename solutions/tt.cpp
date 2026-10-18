#include<bits/stdc++.h>

using namespace std;
using ll = long long;
bool p(string &s,string &d){
    if(s==d)return 1;
    if(d=="")return 0;
    if(s.size()<=d.size())return 0;
    if(d=="L"&&s=="RL")return 1;
    if(d=="R"&&s=="RL")return 1;
    int l=0,r=s.size();
    if(d[0]=='L'){
        if(d.back()=='R'){
            while(l<s.size()&&s[l]!='L')l++;
            while(r>=0&&s[r]!='R')r--;
            if(l>=s.size()||r<0)return 0;
            string ss=s.substr(l+1,r-1),dd=d.substr(1,d.size()-1);
            return p(ss,dd);
        }
        else {
            if(s.back()!='L')return 0;
            if(d.size()==1)return 1;
             while(l<s.size()&&s[l]!='L')l++;
            while(r>=0&&s[r]!='L')r--;
            if(l>=s.size()||r<0||l==r)return 0;
            string ss=s.substr(l+1,r-1),dd=d.substr(1,d.size()-1);
            return p(ss,dd);
        }
    }
    else {
        if(d.back()=='R'){
            if(s[0]!='R')return 0;
            if(d.size()==1)return 1;
            while(l<s.size()&&s[l]!='R')l++;
            while(r>=0&&s[r]!='R')r--;
            if(l>=s.size()||r<0||l==r)return 0;
            string ss=s.substr(l+1,r-1),dd=d.substr(1,d.size()-1);
            return p(ss,dd);
        }
        else {
            if(s[0]!='R'||s.back()!='L')return 0;
            while(l<s.size()&&s[l]!='R')l++;
            while(r>=0&&s[r]!='L')r--;
            if(l>=s.size()||r<0)return 0;
            string ss=s.substr(l+1,r-1),dd=d.substr(1,d.size()-1);
            return p(ss,dd);
        }
    }
}
void solve()
{
    string s; cin>>s;
    int q; cin>>q;
    
    for(int i=0; i<q; i++){
        string d;cin>>d;
        if(p(s,d))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s="9900";
    string d=s.substr(3,4);
    cout<<d;

    return 0;
}