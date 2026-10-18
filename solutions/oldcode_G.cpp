#include <bits/stdc++.h>

using namespace std;

map<vector<int>, bool> memo;

bool dfs(int c0, int c1, int c2, int c3) {
    vector<int> state = {c0, c1, c2, c3};
    if (memo.count(state)) return memo[state];
    
    bool win = false;
    // 尝试所有合法的操作，只要有一种操作能让对手面临必败态，当前玩家就必胜
    if (c0 >= 2 && !dfs(c0 - 1, c1, c2, c3)) win = true; // 0+0=0
    if (c0 >= 1 && c1 >= 1 && !dfs(c0 - 1, c1, c2, c3)) win = true; // 0+1=1
    if (c0 >= 1 && c2 >= 1 && !dfs(c0 - 1, c1, c2, c3)) win = true; // 0+2=2
    if (c0 >= 1 && c3 >= 1 && !dfs(c0 - 1, c1, c2, c3)) win = true; // 0+3=3
    
    if (c1 >= 2 && !dfs(c0, c1 - 2, c2 + 1, c3)) win = true; // 1+1=2
    if (c1 >= 1 && c2 >= 1 && !dfs(c0, c1 - 1, c2 - 1, c3 + 1)) win = true; // 1+2=3
    
    return memo[state] = win;
}

int main() {
    // 控制变量法打印表格
    // 观察发现 c3 其实只在和 0 结合时有用，我们先固定 c3=0 看看 c1 和 c2 的关系
    int c3 = 0;
    for (int c0 = 0; c0 <= 1; c0++) { // 看 c0 的奇偶性影响
        cout << "When c0 = " << c0 << ":" << endl;
        for (int c1 = 0; c1 <= 5; c1++) {
            for (int c2 = 0; c2 <= 5; c2++) {
                cout << (dfs(c0, c1, c2, c3) ? "W " : "L ");
            }
            cout << endl;
        }
        cout << "-----------------" << endl;
    }
    return 0;
}