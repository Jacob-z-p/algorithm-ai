/**
 * 代码由 Cursor Grok 4.6 High Fast 生成
 */
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // 正子集 P、负子集 N：sum(P) - sum(N) = target，且 sum(P) + sum(N) = sum
        // 故 2 * sum(P) = sum + target，需非负偶数
        if (abs(target) > sum || (sum + target) % 2 != 0) {
            return 0;
        }
        int cap = (sum + target) / 2;

        // 01 背包求方案数：dp[j] = 选出若干个数恰好凑成 j 的方案数
        vector<int> dp(cap + 1, 0);
        dp[0] = 1;
        for (int x : nums) {
            for (int j = cap; j >= x; --j) {
                dp[j] += dp[j - x];
            }
        }
        return dp[cap];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << Solution().findTargetSumWays(nums, target) << '\n';
    return 0;
}
