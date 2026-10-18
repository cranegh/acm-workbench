#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// 将字符映射为点数 2-14
int get_rank(char c) {
    if (c >= '2' && c <= '9') return c - '0';
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    if (c == 'A') return 14;
    return 0;
}

// 定义一张牌
struct Card {
    int rank;
    char suit;
    bool operator==(const Card& o) const { return rank == o.rank && suit == o.suit; }
};

// 核心：评估5张牌，返回可比大小的vector
vector<int> get_score(vector<Card> hand) {
    // 按点数降序排列
    sort(hand.begin(), hand.end(), [](const Card& a, const Card& b){
        return a.rank > b.rank;
    });

    bool is_flush = true;
    for (int i = 1; i < 5; i++) {
        if (hand[i].suit != hand[0].suit) is_flush = false;
    }

    bool is_straight = false;
    vector<int> ranks;
    for (Card c : hand) ranks.push_back(c.rank);

    // 判断顺子，处理A 5 4 3 2特例
    if (ranks[0] == 14 && ranks[1] == 5 && ranks[2] == 4 && ranks[3] == 3 && ranks[4] == 2) {
        is_straight = true;
        // 把A放到最后，当作1看待，方便后面Tie-breaker
        ranks = {5, 4, 3, 2, 1}; 
    } else {
        is_straight = true;
        for (int i = 0; i < 4; i++) {
            if (ranks[i] - 1 != ranks[i+1]) {
                is_straight = false;
                break;
            }
        }
    }

    // 统计频次
    map<int, int> counts;
    for (int r : ranks) counts[r]++;
    // 按照 (频次降序, 点数降序) 排序
    vector<pair<int, int>> freq;
    for (auto kv : counts) freq.push_back({kv.second, kv.first});
    sort(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    });

    // 组装最终score
    vector<int> score;
    // 0: Highcard, 1: Pair, 2: Two pairs, 3: Three of a kind, 4: Straight
    // 5: Flush, 6: Full house, 7: Four of a kind, 8: Straight flush
    
    if (is_flush && is_straight && ranks[0] == 14) score.push_back(9); // 题目里的Royal Flush等同于最高点的同花顺，为了严谨单独设为9
    else if (is_flush && is_straight) score.push_back(8);
    else if (freq[0].first == 4) score.push_back(7);
    else if (freq[0].first == 3 && freq[1].first == 2) score.push_back(6);
    else if (is_flush) score.push_back(5);
    else if (is_straight) score.push_back(4);
    else if (freq[0].first == 3) score.push_back(3);
    else if (freq[0].first == 2 && freq[1].first == 2) score.push_back(2);
    else if (freq[0].first == 2) score.push_back(1);
    else score.push_back(0);

    // 压入Tie-breaker
    for (auto kv : freq) {
        for(int i = 0; i < kv.first; ++i) { // 按照频次还原张数，其实只要kv.second即可，但全压入不影响字典序
            score.push_back(kv.second);
        }
    }
    return score;
}

// 比较两手牌，赢1，平0，输-1
int compare_hands(vector<Card>& my_hand, vector<Card>& opp_hand) {
    vector<int> s1 = get_score(my_hand);
    vector<int> s2 = get_score(opp_hand);
    if (s1 > s2) return 1;
    if (s1 < s2) return -1;
    return 0;
}

void solve() {
    vector<Card> my_known(4), opp_known(4);
    vector<Card> all_deck;
    string suits = "CDHS";
    
    // 生成整副牌
    for (int r = 2; r <= 14; r++) {
        for (char s : suits) {
            all_deck.push_back({r, s});
        }
    }

    auto read_card = [](Card& c) {
        string s; cin >> s;
        c.rank = get_rank(s[0]);
        c.suit = s[1];
    };

    for (int i = 0; i < 4; i++) read_card(my_known[i]);
    for (int i = 0; i < 4; i++) read_card(opp_known[i]);

    // 找出剩余牌
    vector<Card> pool;
    for (Card c : all_deck) {
        bool used = false;
        for (Card kc : my_known) if (kc == c) used = true;
        for (Card kc : opp_known) if (kc == c) used = true;
        if (!used) pool.push_back(c);
    }

    int final_res = 2; // 无穷大

    // 法国赌神先选
    for (int i = 0; i < pool.size(); i++) {
        int max_my_res = -2; // 无穷小
        Card opp_hidden = pool[i];
        
        // 你后选
        for (int j = 0; j < pool.size(); j++) {
            if (i == j) continue;
            Card my_hidden = pool[j];
            
            vector<Card> my_full = my_known; my_full.push_back(my_hidden);
            vector<Card> opp_full = opp_known; opp_full.push_back(opp_hidden);
            
            int cur_res = compare_hands(my_full, opp_full);
            max_my_res = max(max_my_res, cur_res);
        }
        // 赌神知道你会尽量赢，所以他会选择让你结果最差的那张牌
        final_res = min(final_res, max_my_res);
    }

    if (final_res == 1) cout << "WoYaoYanPai\n";
    else if (final_res == -1) cout << "GeiWoCaPiXie\n";
    else cout << "PaiMeiYouWenTi\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    if (cin >> T) {
        while (T--) solve();
    }
    return 0;
}