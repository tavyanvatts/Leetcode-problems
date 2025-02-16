class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m + n - 1; i > m - 1; i--) {
            swap(nums1[i], nums2[m + n - 1 - i]);
        }
        sort(nums1.begin(), nums1.end());
    }
};
