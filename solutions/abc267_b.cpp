#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// const int N = 5;
// int col[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;
    if(s[0] == '1'){
        cout<<"No\n";
        return 0;
    }

    int l = 0, r = 0;
    for(int i=1; i<=7; i++){
        bool has_standing = false;
        if(i == 1){
            if(s[6] == '1') has_standing = true;
        }
        else if(i == 2){
            if(s[3] == '1') has_standing = true;
        }
        else if(i == 3){
            if(s[1] == '1' || s[7] == '1') has_standing = true;
        }
        else if(i == 4){
            if(s[4] == '1') has_standing = true;
        }
        else if(i == 5){
            if(s[2] == '1' || s[8] == '1') has_standing = true;
        }
        else if(i == 6){
            if(s[5] == '1') has_standing = true;
        }
        else if(i == 7){
            if(s[9] == '1') has_standing = true;
        }

        if(has_standing){
            if(l == 0) l = i;
            else r = i;
        }

    }

    if(r <= l){
        cout<<"No\n";
        return 0;
    }

    bool ok = false;
    for(int i=l+1; i<r; i++){
        bool has_onlydown = false;
        if(i == 1){
            if(s[6] == '0') has_onlydown = true;
        }
        else if(i == 2){
            if(s[3] == '0') has_onlydown = true;
        }
        else if(i == 3){
            if(s[1] == '0' && s[7] == '0') has_onlydown = true;
        }
        else if(i == 4){
            if(s[4] == '0') has_onlydown = true;
        }
        else if(i == 5){
            if(s[2] == '0' && s[8] == '0') has_onlydown = true;
        }
        else if(i == 6){
            if(s[0]=='0' && s[5] == '0') has_onlydown = true;
        }
        else if(i == 7){
            if(s[9] == '0') has_onlydown = true;
        }

        if(has_onlydown){
            ok = true;
            break;
        }

    }
    
    if(ok) cout<<"Yes\n";
    else cout<<"No\n";
}