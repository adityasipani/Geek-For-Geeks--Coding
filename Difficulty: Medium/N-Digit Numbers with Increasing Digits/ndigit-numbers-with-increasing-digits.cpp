class Solution {
public:
    void generate(int start, int len, int n, int num, vector<int>& ans) {
        if (len == n) {
            ans.push_back(num);
            return;
        }

        for (int d = start; d <= 9; d++) {
            generate(d + 1, len + 1, n, num * 10 + d, ans);
        }
    }

    vector<int> increasingNumbers(int n) {
        vector<int> ans;

        if (n > 10) return ans;

        if (n == 1) {
            for (int i = 0; i <= 9; i++)
                ans.push_back(i);
            return ans;
        }

        generate(1, 0, n, 0, ans);
        return ans;
    }
};