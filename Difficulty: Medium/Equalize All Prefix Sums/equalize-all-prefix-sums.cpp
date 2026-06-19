class Solution {
public:
    vector<int> optimalArray(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);

        long long prefix = 0;          // sum till current index
        vector<long long> pref(n);

        for (int i = 0; i < n; i++) {
            prefix += arr[i];
            pref[i] = prefix;
        }

        for (int i = 0; i < n; i++) {
            int mid = i / 2;

            long long left =
                1LL * arr[mid] * (mid + 1) - pref[mid];

            long long right =
                (pref[i] - pref[mid]) -
                1LL * arr[mid] * (i - mid);

            ans[i] = left + right;
        }

        return ans;
    }
};