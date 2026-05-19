class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        unordered_map<long long, int> freq;
        
        for (long long x : arr) {
            
            // Handle target = 0 separately
            if (target == 0) {
                if ((x == 0 && !freq.empty()) || 
                    (x != 0 && freq.count(0))) {
                    return true;
                }
            } 
            else {
                if (x != 0 && target % x == 0) {
                    long long need = target / x;
                    if (freq.count(need)) {
                        return true;
                    }
                }
            }
            
            freq[x]++;
        }
        
        return false;
    }
};