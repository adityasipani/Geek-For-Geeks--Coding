class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        
        // Count total number of 1s
        int k = 0;
        for (int x : arr) {
            if (x == 1) k++;
        }
        
        // If no 1s present
        if (k == 0) return -1;
        
        // Count 1s in first window of size k
        int currOnes = 0;
        for (int i = 0; i < k; i++) {
            if (arr[i] == 1) currOnes++;
        }
        
        int maxOnes = currOnes;
        
        // Sliding window
        for (int i = k; i < n; i++) {
            if (arr[i] == 1) currOnes++;
            if (arr[i - k] == 1) currOnes--;
            
            maxOnes = max(maxOnes, currOnes);
        }
        
        return k - maxOnes;
    }
};