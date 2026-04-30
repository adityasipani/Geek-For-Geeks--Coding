class Solution {
public:
    bool isMaxHeap(vector<int>& arr) {
        int n = arr.size();

        // Check all parent nodes
        for (int i = 0; i <= (n - 2) / 2; i++) {

            int left = 2 * i + 1;
            int right = 2 * i + 2;

            // Check left child
            if (left < n && arr[i] < arr[left]) {
                return false;
            }

            // Check right child
            if (right < n && arr[i] < arr[right]) {
                return false;
            }
        }

        return true;
    }
};