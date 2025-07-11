class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1, right = n - 1, mergeIdx = m + n - 1;

        // Merge from the back
        while (left >= 0 && right >= 0) {
            if (nums1[left] > nums2[right]) {
                nums1[mergeIdx--] = nums1[left--];
            } else {
                nums1[mergeIdx--] = nums2[right--];
            }
        }

        // If nums2 has remaining elements
        while (right >= 0) {
            nums1[mergeIdx--] = nums2[right--];
        }
    }   
};