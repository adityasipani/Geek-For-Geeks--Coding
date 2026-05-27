class Solution {
  public:
    bool wifiRange(string s, int x) {
        int n = s.length();

        for (int i = 0; i < n; i++) {
            bool covered = false;

            int left = max(0, i - x);
            int right = min(n - 1, i + x);

            for (int j = left; j <= right; j++) {
                if (s[j] == '1') {
                    covered = true;
                    break;
                }
            }

            if (!covered)
                return false;
        }

        return true;
    }
};