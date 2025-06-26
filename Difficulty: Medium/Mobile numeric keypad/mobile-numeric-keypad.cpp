class Solution {
public: // code written by sunny
    int getCount(int n) {
        if (n == 1) return 10;

        vector<vector<int>> dp(n + 1, vector<int>(10, 0)); 
        for (int i = 0; i <= 9; i++) {
            dp[1][i] = 1;
        } 
        unordered_map<int, vector<int>> moves = {
            {0, {0, 8}},
            {1, {1, 2, 4}},
            {2, {2, 1, 3, 5}},
            {3, {3, 2, 6}},
            {4, {4, 1, 5, 7}},
            {5, {5, 2, 4, 6, 8}},
            {6, {6, 3, 5, 9}},
            {7, {7, 4, 8}},
            {8, {8, 5, 7, 9, 0}},
            {9, {9, 6, 8}}
        }; 
        for (int len = 2; len <= n; len++) {
            for (int digit = 0; digit <= 9; digit++) {
                for (int prev : moves[digit]) {
                    dp[len][digit] += dp[len - 1][prev];
                }
            }
        } 
        int total = 0;
        for (int digit = 0; digit <= 9; digit++) {
            total += dp[n][digit];
        }

        return total;
    }
};
