#include<bits/stdc++.h>
using namespace std;
int T;
vector<string> v;
map<string, int> m;
bool check(){
    bool vis[15];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < v.size(); i++){
        if(v[i] == "1s") vis[1] = 1;
        else if(v[i] == "1p") vis[2] = 1;
        else if(v[i] == "1m") vis[3] = 1;
        else if(v[i] == "9s") vis[4] = 1;
        else if(v[i] == "9p") vis[5] = 1;
        else if(v[i] == "9m") vis[6] = 1;
        else if(v[i] == "1z") vis[7] = 1;
        else if(v[i] == "2z") vis[8] = 1;
        else if(v[i] == "3z") vis[9] = 1;
        else if(v[i] == "4z") vis[10] = 1;
        else if(v[i] == "5z") vis[11] = 1;
        else if(v[i] == "6z") vis[12] = 1;
        else if(v[i] == "7z") vis[13] = 1;
    }
    for(int i = 1; i <= 13; i++)
        if(!vis[i]) return false;
    return true;
}
int main(){
    cin >> T;
    while(T--){
        v.clear();
        m.clear();
        string s;
        cin >> s;
        for(int i = 0; i < s.length(); i += 2){
            string tmp = s.substr(i, 2);
            if(m.find(tmp) == m.end()) v.push_back(tmp);
            m[tmp]++;
        }
        if(v.size() == 7) cout << "7 Pairs";
        else if(v.size() == 13 && check()) cout << "Thirteen Orphans";
        else cout << "Otherwise";
        cout << endl;
    }
}