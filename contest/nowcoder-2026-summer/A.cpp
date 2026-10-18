#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 优化输入输出
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    // cnt[j][state] 表示：针对第 j 位和第 j+1 位，构成状态为 state 的数字个数
    // state 的二进制定义为: (bit_{j+1} << 1) | bit_j
    vector<vector<int>> cnt(30, vector<int>(4, 0));

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 30; ++j) {
            int bit_j = (a[i] >> j) & 1;
            int bit_j1 = (a[i] >> (j + 1)) & 1;
            int state = (bit_j1 << 1) | bit_j;
            cnt[j][state]++;
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int type, x;
        cin >> type >> x;

        long long total_f = 0;

        for (int j = 0; j < 30; ++j) {
            int op_bit_j = (x >> j) & 1;
            int op_bit_j1 = (x >> (j + 1)) & 1;
            int op_state = (op_bit_j1 << 1) | op_bit_j;

            vector<int> nxt_cnt(4, 0);

            for (int s = 0; s < 4; ++s) {
                if (cnt[j][s] == 0) continue;
                
                int nxt_s = 0;
                if (type == 1) { // AND
                    nxt_s = s & op_state;
                } else if (type == 2) { // OR
                    nxt_s = s | op_state;
                } else if (type == 3) { // XOR
                    nxt_s = s ^ op_state;
                }
                nxt_cnt[nxt_s] += cnt[j][s];
            }

            cnt[j] = nxt_cnt;
            // 我们需要的 f(x) 贡献是：第 j 位为 1 且第 j+1 位为 0
            // 这对应到二进制组合就是 01，即十进制的 1
            total_f += cnt[j][1];
        }
        cout << total_f << "\n";
    }

    return 0;
}