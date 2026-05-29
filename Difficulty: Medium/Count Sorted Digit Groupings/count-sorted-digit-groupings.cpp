class Solution {
  public:
    
    int dp[105][905];
    
    int solve(int idx, int prevSum, string &s) {
        int n = s.size();
        
        // Reached end => one valid grouping
        if (idx == n)
            return 1;
        
        // Memoized result
        if (dp[idx][prevSum] != -1)
            return dp[idx][prevSum];
        
        int ans = 0;
        int currSum = 0;
        
        // Try all possible substrings starting at idx
        for (int j = idx; j < n; j++) {
            currSum += (s[j] - '0');
            
            // Non-decreasing condition
            if (currSum >= prevSum) {
                ans += solve(j + 1, currSum, s);
            }
        }
        
        return dp[idx][prevSum] = ans;
    }
    
    int validGroups(string &s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s);
    }
};