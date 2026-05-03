class Solution {
  public:
  
    // Function to count set bits
    int countSetBits(int n) {
        return __builtin_popcount(n);
    }
    
    vector<int> sortBySetBitCount(vector<int>& arr) {
        
        // Stable sort based on set bit count in descending order
        stable_sort(arr.begin(), arr.end(), [&](int a, int b) {
            return countSetBits(a) > countSetBits(b);
        });
        
        return arr;
    }
};