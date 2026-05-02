class Solution {
  public:
    int findPosition(int n) {
        if (n == 0 || (n & (n - 1)))
            return -1;
            
        return __builtin_ctz(n) + 1;
    }
};