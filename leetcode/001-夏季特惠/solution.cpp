/**
 * 代码由 Cursor Grok 4.6 High Fast 生成
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    // 心理不亏条件：sum(优惠) >= sum(现价) - X
    // 即 sum(a_i - b_i) >= sum(b_i) - X
    // 化简得：sum(2 * b_i - a_i) <= X
    // 每个游戏的“体积”为 cost = 2*b - a，价值为快乐值 w
    long long extra_happy = 0;
    vector<pair<int, long long>> items;  // (cost, w)，仅保留 cost > 0

    for (int i = 0; i < n; ++i) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        int cost = 2 * b - a;
        if (cost <= 0) {
            // 体积非正且快乐值为正：必选，同时把背包容量扩大 -cost
            x -= cost;
            extra_happy += w;
        } else {
            items.push_back({cost, w});
        }
    }

    // 01 背包：dp[j] = 容量为 j 时的最大快乐值
    vector<long long> dp(x + 1, 0);
    for (auto [cost, w] : items) {
        for (int j = x; j >= cost; --j) {
            dp[j] = max(dp[j], dp[j - cost] + w);
        }
    }

    cout << dp[x] + extra_happy << '\n';
    return 0;
}
