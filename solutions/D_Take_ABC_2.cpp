#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    string s; cin>>s;

    ll cnta=0,cntab=0,cntabc=0;

    for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='A') cnta++;
        else if(s[i]=='B'){
            if(cnta){
                cnta--;
                cntab++;
            }
        }else if(s[i]=='C'){
            if(cntab){
                cntab--;
                cntabc++;
            }
        }
    }

    cout<<cntabc;

    return 0;
}