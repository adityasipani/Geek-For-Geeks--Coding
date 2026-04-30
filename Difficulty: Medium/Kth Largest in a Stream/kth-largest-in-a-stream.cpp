class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> ans;
        
        for (int x : arr) {
            // Insert current element
            minHeap.push(x);
            
            // Keep only k largest elements in heap
            if (minHeap.size() > k) {
                minHeap.pop();
            }
            
            // If less than k elements, kth largest doesn't exist
            if (minHeap.size() < k) {
                ans.push_back(-1);
            } 
            else {
                // Top of min heap is kth largest
                ans.push_back(minHeap.top());
            }
        }
        
        return ans;
    }
};